#include "../header/Bundle.hpp"

Bundle::Bundle(const std::string& title, int ISBN, const std::string& genre, const std::string& subgenre, const std::vector<Content*>& contentList = {}) : Content(title, ISBN, genre, subgenre) {
    for (Content* content : contentList)
        if (this->contentList.find(content->GetISBN()) != this->contentList.end())
            this->contentList.insert({content->GetISBN(), content});
}

Bundle::~Bundle() {
    for (std::pair<int, Content*> content : this->contentList)
        delete content.second;
}

void Bundle::Display(std::string indent) {
    std::cout << indent << "Title: " << this->title;
    std::cout << "\n" << indent << "ISBN: " << this->ISBN;
    std::cout << "\n" << indent << "Genre: " << this->genre;
    std::cout << "\n" << indent << "SubGenre: " << this->subgenre;
    std::cout << "\n" << indent << "Frequency: " << this->frequency << std::endl;
    for (std::pair<int, Content*> content : this->contentList)
        content.second->Display(indent + "  ");
}