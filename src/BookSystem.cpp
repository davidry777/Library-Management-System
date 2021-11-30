#include "../header/BookSystem.hpp"

using json = nlohmann::json;

BookSystem::BookSystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& passedDueFile) : catalogueFile(catalogueFile), checkedOutFile(checkedOutFile), passedDueFile(passedDueFile) {
    LoadCatalogue();
}

BookSystem::~BookSystem() {
    for (pair<long long, Content*> content : this->catalogue)
        delete content.second;
    for (CheckOutData* data : this->passedDue)
        delete data;
    for (CheckOutData* data : this->checkedOut)
        delete data;
}

void BookSystem::SaveCatalogue(string file) {
    if (file == "null")
        file = this->catalogueFile;
    json catalogueJSON;

    int i = 1;
    for (pair<long long, Content*> book : this->catalogue) {
        catalogueJSON[i]["title"] = book.second->GetTitle();
        catalogueJSON[i]["isbn"] = book.second->GetISBN();
        catalogueJSON[i]["genre"] = book.second->GetGenre();
        catalogueJSON[i]["author"] = book.second->GetAuthor();
        catalogueJSON[i]["frequency"] = book.second->GetFrequency();
    }
    ofstream outFS(file);
    outFS << std::setw(4) << catalogueJSON << endl;
    outFS.close();
}

void BookSystem::LoadCatalogue() {
    std::ifstream inFS(catalogueFile);
    json catalogueJSON;

    inFS >> catalogueJSON;
    inFS.close();

    for (auto content : catalogueJSON) {
        Content* newContent = new Book(content["title"], content["isbn"], content["genre"], content["author"], content["frequency"]);
        if (!AddContent(newContent))
            delete newContent;
    }
}

void BookSystem::SaveCheckedOut(string file) {
    if (file == "null")
        file = this->checkedOutFile;
    json checkedOutJSON;

    int i = 1;
    for (CheckOutData* data : this->checkedOut) {
        checkedOutJSON[i]["time"] = data->timeCheckedOut;
        checkedOutJSON[i]["content_isbn"] = data->contentCheckedOut->GetISBN();
        checkedOutJSON[i]["user_id"] = data->userCheckedOut->GetId();
        checkedOutJSON[i]["over_time"] = data->overTime;
    }
    
    ofstream outFS(file);
    outFS << std::setw(4) << checkedOutJSON << endl;
    outFS.close();
}

void BookSystem::LoadCheckedOut(UserSystem* us) {
    ifstream inFS(checkedOutFile);
    json checkedOutJSON;

    inFS >> checkedOutJSON;
    inFS.close();

    for (auto data : checkedOutJSON) {
        time_t dataTime = data["time"];
        Content* dataContent = this->catalogue.at(data["content_isbn"]);
        Person* dataUser = us->GetPerson(data["user_id"]);
        bool dataOvertime = data["over_time"];
        CheckOutData* newData = new CheckOutData(dataTime, dataContent, dataUser, dataOvertime);
        checkedOut.push_back(newData);
    }
}

void BookSystem::SavePassedDue(string file) {
    if (file == "null")
        file = this->passedDueFile;
    json passedDueJSON;

    int i = 1;
    for (CheckOutData* data : this->passedDue) {
        passedDueJSON[i]["time"] = data->timeCheckedOut;
        passedDueJSON[i]["content_isbn"] = data->contentCheckedOut->GetISBN();
        passedDueJSON[i]["user_id"] = data->userCheckedOut->GetId();
        passedDueJSON[i]["over_time"] = data->overTime;
    }

    ofstream outFS(file);
    outFS << std::setw(4) << passedDueJSON << endl;
    outFS.close();
}

void BookSystem::LoadPassedDue(UserSystem* us) {
    ifstream inFS(passedDueFile);
    if (!inFS.is_open()) {
        cout << "Cannot find '" << passedDueFile << "'.Exiting" << endl;
        exit(1);
    }
    json passed_dueJSON;
    inFS >> passed_dueJSON;
    inFS.close();
    for (auto data : passed_dueJSON) {
        time_t dataTime = data["time"];
        Content* dataContent = this->catalogue.at(data["content_isbn"]);
        Person* dataUser = us->GetPerson(data["user_id"]);
        bool dataOvertime = data["over_time"];
        CheckOutData* newData = new CheckOutData(dataTime, dataContent, dataUser, dataOvertime);
        passedDue.push_back(newData);
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
std::vector<CheckOutData*>& BookSystem::GetPassedDue() {
    return passedDue;
}
std::deque<CheckOutData*>& BookSystem::GetCheckedOut() {
    return checkedOut;
}


bool BookSystem::AddContent(Content* content) {
    if (this->catalogue.find(content->GetISBN()) == this->catalogue.end()) {
        this->catalogue.insert({content->GetISBN(), content});
        return true;
    }
    std::cout << "Error adding content. ISBN number " << content->GetISBN() << " is already in use for " << this->catalogue.at(content->GetISBN()) << "!" << std::endl;
    return false; 
}
bool BookSystem::MakeBundle(const std::string& title, long long newISBN, const std::string& genre, const std::vector<long long> ISBNLists, int frequency) {
    std::vector<Content*> newContentList;
    for (long long ISBN : ISBNLists) {
        if (this->catalogue.find(ISBN) != this->catalogue.end())
            newContentList.push_back(this->catalogue.at(ISBN));
        else
            cout << "Error. Could not find ISBN " << ISBN << " in catalogue!" << endl;
    }
    Content* newContent = new Bundle(title, newISBN, genre, newContentList);
    if (!AddContent(newContent)) {
        cout << "Error. Content with ISBN " << newISBN << " already exists in the catalogue!" << endl;
        delete newContent;
        return false;
    }
    return true;
}
bool BookSystem::RemoveContent(long long ISBN) {
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        this->catalogue.erase(ISBN);
        return true;
    }
    std::cout << "Error removing content. ISBN number " << ISBN << " does not exist in the catalogue!" << std::endl;
    return false;
}

CheckOutData* BookSystem::CheckOut(Person* person, long long ISBN) {
    CheckOutData* data = nullptr;
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        this->catalogue.at(ISBN)->AddFrequency();
        data = new CheckOutData(time(0), this->catalogue.at(ISBN), person);
        this->checkedOut.push_back(data);
    }
    else
        std::cout << "ISBN " << ISBN << " not in catalogue!" << std::endl;
    return data;
}
bool BookSystem::ReturnContent(Person* person, long long ISBN) {
    for (std::vector<CheckOutData*>::iterator it = passedDue.begin(); it != passedDue.end(); ++it)
        if ((*it)->userCheckedOut == person && (*it)->contentCheckedOut->GetISBN() == ISBN) {
            CheckOutData* temp = *it;
            passedDue.erase(it);
            delete temp;
            return true;
        }
    for (std::deque<CheckOutData*>::iterator it = checkedOut.begin(); it != checkedOut.end(); ++it)
        if ((*it)->userCheckedOut == person && (*it)->contentCheckedOut->GetISBN() == ISBN) {
            CheckOutData* temp = *it;
            checkedOut.erase(it);
            delete temp;
            return true;
        }
    std::cout << person->GetName() << " has not checked out ISBN " << ISBN << "!" << std::endl;
    return false;
}
void BookSystem::CheckExpiration() {
    if (!this->checkedOut.empty() && std::time(0) - this->checkedOut.front()->timeCheckedOut >= 259200) {
        this->checkedOut.front()->overTime = true;
        this->passedDue.push_back(this->checkedOut.front());
        this->checkedOut.pop_front();
        this->CheckExpiration();
    }
}