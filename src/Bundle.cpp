#include "../header/Bundle.hpp"

Bundle::Bundle(const std::string& title, int ISBN, const std::string& genre, const std::vector<Content*>& contentList = {}) : Content(title, ISBN, genre) {
    for (Content* content : contentList)
        if (this->contentList.find(content->GetISBN()) != this->contentList.end())
            this->contentList.insert({content->GetISBN(), content});
}

Bundle::~Bundle() {
    for (std::pair<int, Content*> content : this->contentList)
        delete content.second;
}

std::string Bundle::Display(std::string indent) {
    std::string outputString = "";
    std::cout << indent << "Title: " << this->title;
    std::cout << "\n" << indent << "ISBN: " << this->ISBN;
    std::cout << "\n" << indent << "Genre: " << this->genre;
    std::cout << "\n" << indent << "Frequency: " << this->frequency << std::endl;
    for (std::pair<int, Content*> content : this->contentList)
        content.second->Display(indent + "  ");
    return outputString;
}