#include "../header/BookSystem.hpp"

using json = nlohmann::json;
using namespace std;

BookSystem::BookSystem(const string& catF, const string& coF, int maxSecs) : catalogueFile(catF), checkedOutFile(coF), maximumSeconds(maxSecs) {
    LoadCatalogue();
}
BookSystem::~BookSystem() {
    for (pair<long long, Content*> content : this->catalogue)
        DeallocateContent(content.second);
    for (pair<int, std::vector<CheckOutData*>> dataPair : this->checkedOut)
        for (CheckOutData* data : dataPair.second)
            delete data;
}
void BookSystem::DeallocateContent(Content* content) {
    if (content->GetType() == "Bundle")
        delete dynamic_cast<Bundle*>(content);
    else if (content->GetType() == "Book")
        delete content;
    else {
        cout << "error. object not defined" << endl;
    }
}
void BookSystem::SaveCatalogue(string file) {
    if (file == "null")
        file = this->catalogueFile;
    json catalogueJSON;

    int i = 0;
    for (pair<long long, Content*> book : this->catalogue) {
        if (book.second->GetType() == "Bundle")
            continue;
        catalogueJSON[i]["title"] = book.second->GetTitle();
        catalogueJSON[i]["isbn"] = book.second->GetISBN();
        catalogueJSON[i]["genre"] = book.second->GetGenre();
        catalogueJSON[i]["author"] = book.second->GetAuthor();
        catalogueJSON[i]["frequency"] = book.second->GetFrequency();
        ++i;
    }
    ofstream outFS(file);
    outFS << std::setw(4) << catalogueJSON << endl;
    outFS.close();
}
void BookSystem::LoadCatalogue() {
    std::ifstream inFS(catalogueFile);
    json catalogueJSON;
    try {
        inFS >> catalogueJSON;
        inFS.close();
    }
    catch (...) {
        cout << "Warning: " << catalogueFile << " was not found. No catalogue data will be loaded." << endl;
        return;
    }
    for (auto content : catalogueJSON) {
        Content* newContent = new Book(content["title"], content["isbn"], content["genre"], content["author"], content["frequency"]);
        AddContent(newContent);
    }
}
void BookSystem::SaveCheckedOut(string file) {
    if (file == "null")
        file = this->checkedOutFile;
    json checkedOutJSON;

    int i = 0;
    for (pair<int, std::vector<CheckOutData*>> dataPair : this->checkedOut) {
        for (CheckOutData* &data : dataPair.second) {
            checkedOutJSON[i]["time"] = data->timeCheckedOut;
            checkedOutJSON[i]["content_isbn"] = data->contentCheckedOut->GetISBN();
            checkedOutJSON[i]["over_time"] = data->overTime;
            checkedOutJSON[i]["user_id"] = data->userCheckedOut->GetId();
        }
        ++i;
    }
    
    ofstream outFS(file);
    outFS << std::setw(4) << checkedOutJSON << endl;
    outFS.close();
}
void BookSystem::LoadCheckedOut(std::unordered_map<int, Person *> us) {
    ifstream inFS(checkedOutFile);
    json checkedOutJSON;
    try {
        inFS >> checkedOutJSON;
        inFS.close();
    }
    catch (...) {
        cout << "Warning: " << checkedOutFile << " was not found. No checked out data will be loaded." << endl;
        return;
    }
    
    for (auto data : checkedOutJSON) {
        time_t dataTime = data["time"];
        if (this->catalogue.find((data["content_isbn"])) == this->catalogue.end()) {
            continue;
        }
        Content* dataContent = this->catalogue.at(data["content_isbn"]);
        if (us.find((data["user_id"])) == us.end()) {
            cout << "error constructing user " << data["user_id"] << ". User does not exist in person map." << endl;
            continue;
        }
        Person* dataUser = us.at(data["user_id"]);
        bool dataOvertime = data["over_time"];
        CheckOutData* newData = new CheckOutData(dataTime, dataContent, dataUser, dataOvertime);
        if (this->checkedOut.find(dataUser->GetId()) == this->checkedOut.end())
            this->checkedOut.insert({dataUser->GetId(), {newData}});
        else
            this->checkedOut.at(data).push_back(newData);
    }
}
std::unordered_map<long long, Content*>& BookSystem::GetCatalogue() {
    return this->catalogue;
}
Content* BookSystem::GetContent(long long ISBN) {
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        return this->catalogue.at(ISBN);
    }
    std::cout << "Error finding ISBN. ISBN number " << ISBN << " does not exist in catalogue!" << std::endl;
    return nullptr;
}
unordered_map<int, std::vector<CheckOutData*>>& BookSystem::GetCheckedOut() {
    return this->checkedOut;
}
bool BookSystem::AddContent(Content* content) {
    if (this->catalogue.find(content->GetISBN()) == this->catalogue.end()) {
        this->catalogue.insert({content->GetISBN(), content});
        return true;
    }
    std::cout << "ISBN " << content->GetISBN() << " already exists" << endl;
    DeallocateContent(content);
    return false; 
}
bool BookSystem::MakeBundle(const std::string& title, long long ISBN, const std::string& genre, const std::vector<Content*>& contents) {
    // If Bundle ISBN exists in catalogue, deallocate everything the bundle holds
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        for (Content* content : contents)
            DeallocateContent(content);
        return false;
    }
    else
        this->catalogue.insert({ISBN, new Bundle(title, ISBN, genre, contents)});
    return true;
}
bool BookSystem::RemoveContent(long long ISBN) {
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        DeallocateContent(this->catalogue.at(ISBN));
        this->catalogue.erase(ISBN);
        return true;
    }
    std::cout << "Error removing content. ISBN number " << ISBN << " does not exist in the catalogue!" << std::endl;
    return false;
}
bool BookSystem::FindInCheckedOutVec(vector<CheckOutData*>& userVec, long long ISBN) {
    for (CheckOutData* &data : userVec)
        if (data->contentCheckedOut->GetISBN() == ISBN)
            return true;
    return false;
}
bool BookSystem::CheckOut(Person* person, long long ISBN) {
    if (person->GetType() != "User") {
        cout << person->GetName() << " is not able to check out books!" << endl;
        return false;
    }
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        if (this->checkedOut.find(person->GetId()) != this->checkedOut.end()) {
            if (this->FindInCheckedOutVec(this->checkedOut.at(person->GetId()), ISBN)) {
                cout << ISBN << " has already been checked out!" << endl;
                return false;
            }
        }
        this->catalogue.at(ISBN)->AddFrequency();
        CheckOutData* data = new CheckOutData(time(0), this->catalogue.at(ISBN), person);
        if (this->checkedOut.find(person->GetId()) == this->checkedOut.end())
            this->checkedOut.insert({person->GetId(), {data}});
        else
            this->checkedOut.at(person->GetId()).push_back(data);
    }
    else {
        std::cout << "ISBN " << ISBN << " not in catalogue!" << std::endl;
        return false;
    }
    cout << "Book has been checked out successfully!" << endl;
    return true;
}
bool BookSystem::ReturnContent(Person* person, long long ISBN) {
    if (checkedOut.find(person->GetId()) != checkedOut.end() && this->catalogue.find(ISBN) != this->catalogue.end()) {
        for (vector<CheckOutData*>::iterator it = checkedOut.at(person->GetId()).begin(); it != checkedOut.at(person->GetId()).end(); ++it) {
            if ((*it)->contentCheckedOut->GetISBN() == ISBN) {
                delete (*it);
                if (this->checkedOut.at(person->GetId()).size() == 1)
                    this->checkedOut.erase(person->GetId());
                else
                    this->checkedOut.at(person->GetId()).erase(it);
                cout << "Book has been returned successfully!" << endl;
                return true;
            }
        }
    }
    cout << person->GetName() << " has not checked out " << ISBN << "!" << endl;
    return false;
}
void BookSystem::CheckExpiration() {
    for (pair<int, vector<CheckOutData*>> dataPair : this->checkedOut) {
        for (CheckOutData* data : dataPair.second) {
            if (time(0) - data->timeCheckedOut >= maximumSeconds && data->overTime == false) {
                data->overTime = true;
                dynamic_cast<User*>(data->userCheckedOut)->PayBalance(-10);
            }
        }
    }
}
std::vector<CheckOutData*> BookSystem::GetUserCheckedOut(Person* user) {
    if (this->checkedOut.find(user->GetId()) != this->checkedOut.end()) {
        return this->checkedOut.at(user->GetId());
    }
    return {};
}