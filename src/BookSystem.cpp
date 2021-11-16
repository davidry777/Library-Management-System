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

std::pair<std::time_t, Content*> BookSystem::CheckOut(int ISBN) {
    std::pair<std::time_t, Content*> timeContent = {0, nullptr};
    if (this->catalogue.find(ISBN) != this->catalogue.end()) {
        timeContent = {std::time(0), this->catalogue.at(ISBN)};
        this->checkedOut.push(timeContent);
    }
    else
        std::cout << "ISBN " << ISBN << " not in catalogue!" << std::endl;
    return timeContent;
}