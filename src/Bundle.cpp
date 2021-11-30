#include "../header/Bundle.hpp"

Bundle::Bundle(const std::string& title, long long ISBN, const std::string& genre, const std::vector<Content*>& contentList, int frequency) : Content(title, ISBN, genre, "", frequency) {
    for (Content* content : contentList) {
        if (this->contentList.find(content->GetISBN()) == this->contentList.end())
            this->contentList.insert({content->GetISBN(), content});
        else {
            std::cout << "ISBN already exist in bundle" << std::endl;
        }
    }
    this->author = GetAuthor();
}

std::string Bundle::GetAuthor() {
    std::string res = "";
    for (std::pair<long long, Content*> content : this->contentList) {
        if (res.size() == 0)
            res += content.second->GetAuthor();
        else if (content.second->GetAuthor() != "")
            res += ", " + content.second->GetAuthor();
    }
    return res;
}

Bundle::~Bundle() {
    for (std::pair<int, Content*> content : this->contentList) {
        if (content.second->GetType() == "Bundle")
            delete dynamic_cast<Bundle*>(content.second);
        else
            delete content.second;
    }
}

std::string Bundle::Display(std::string indent) {
    std::string outputString = "";
    outputString += indent + "Title: " + this->GetTitle();
    outputString += "\n" + indent + "ISBN: " + std::to_string(this->GetISBN());
    outputString += "\n" + indent + "Genre: " + this->GetGenre();
    outputString += "\n" + indent + "Frequency: " + std::to_string(this->GetFrequency()) + "\n";
    for (std::pair<int, Content*> content : this->contentList)
        if (content.second->GetAuthor().size() != 0)
            outputString += content.second->Display(indent + "\t") + "\n";
    return outputString;
}