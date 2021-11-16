#include "../header/BookSystem.hpp"

void BookSystem::AddContent(Content* content) {
    if (this->catalogue.find(content->GetISBN()) == this->catalogue.end()) {
        this->catalogue.insert({content->GetISBN(), content});
    }
    else
        std::cout << "Error adding content. ISBN number " << content->GetISBN() << " is already in use for " << this->catalogue.at(content->GetISBN()) << "!" << std::endl; 
}

void BookSystem::RemoveContent(int ISBN) {
    if (this->catalogue.find(ISBN) != this->catalogue.end())
        this->catalogue.erase(ISBN);
    else
        std::cout << "Error removing content. ISBN number " << ISBN << " does not exist in the catalogue!" << std::endl;
}

CheckOutData* BookSystem::CheckOut(Person* person, int ISBN) {
    CheckOutData* data = nullptr;
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        data = new CheckOutData(std::time(0), this->catalogue.at(ISBN), person);
        this->checkedOut.push_back(data);
    }
    else
        std::cout << "ISBN " << ISBN << " not in catalogue!" << std::endl;
    return data;
}

bool BookSystem::ReturnContent(Person* person, int ISBN) {
    for (deque<CheckOutData*>::iterator it = checkedOut.begin(); it != checkedOut.end(); ++it)
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
    if (checkedOut.empty()) { return; }
    for (deque<CheckOutData*>::iterator it = checkedOut.begin(); it != checkedOut.end(); ++it)
        if ((*it)->overTime == false)
            if (std::time(0) - (*it)->timeCheckedOut >= 259200)
                (*it)->overTime = true;
}