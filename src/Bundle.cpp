#include "../header/Bundle.hpp"

Bundle::Bundle(std::string title, int ISBN, const std::vector<Content*>& contentList = {}) : Content(title, ISBN) {
    for (Content* content : contentList)
        if (this->contentList.find(content->GetISBN()) != this->contentList.end())
            this->contentList.insert({content->GetISBN(), content});
}

Bundle::~Bundle() {
    for (std::pair<int, Content*> content : this->contentList)
        delete content.second;
}

void Bundle::Display() {
    std::cout << this->GetTitle() << " Bundle:";
    for (std::pair<int, Content*> content : this->contentList) {
        std::cout << "  ";
        content.second->Display();
        std::cout << "  ";
    }
}