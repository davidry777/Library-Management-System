#include "../header/BookSystem.hpp"

bool BookSystem::GetContent(int ISBN) {
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        return this->catalogue.at(ISBN);
        return true;
    }
    std::cout << "Error finding ISBN. ISBN number " << ISBN << " does not exist in catalogue!" << std::endl;
    return false;
}

bool BookSystem::AddContent(Content* content) {
    if (this->catalogue.find(content->GetISBN()) == this->catalogue.end()) {
        this->catalogue.insert({content->GetISBN(), content});
        return true;
    }
    std::cout << "Error adding content. ISBN number " << content->GetISBN() << " is already in use for " << this->catalogue.at(content->GetISBN()) << "!" << std::endl;
    return false; 
}

bool BookSystem::RemoveContent(int ISBN) {
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        this->catalogue.erase(ISBN);
        return true;
    }
    std::cout << "Error removing content. ISBN number " << ISBN << " does not exist in the catalogue!" << std::endl;
    return false;
}

CheckOutData* BookSystem::CheckOut(Person* person, int ISBN) {
    CheckOutData* data = nullptr;
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        data = new CheckOutData(time(0), this->catalogue.at(ISBN), person);
        this->checkedOut.push_back(data);
    }
    else
        std::cout << "ISBN " << ISBN << " not in catalogue!" << std::endl;
    return data;
}

bool BookSystem::ReturnContent(Person* person, int ISBN) {
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