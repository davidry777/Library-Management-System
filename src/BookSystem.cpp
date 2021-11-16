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