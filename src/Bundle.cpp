#include "../header/Bundle.hpp"

Bundle::Bundle(const std::string& title, long long ISBN, const std::string& genre, const std::vector<Content*>& list, int frequency) : Content(title, ISBN, genre, "", frequency) {
    for (Content* content : list)
        this->contentList.push_back({content});
    this->author = GetAuthor();
}

Bundle::Bundle(std::string t, long long i, std::string g, std::vector<Content*>& list) : Content(t, i, g, "", 0), contentList(list) {}

std::string Bundle::GetAuthor() {
    std::string res = "";
    for (Content* content : this->contentList) {
        if (res.size() == 0)
            res += content->GetAuthor();
        else if (content->GetAuthor() != "")
            res += ", " + content->GetAuthor();
    }
    return res;
}

Bundle::~Bundle() {
    for (Content* content : this->contentList) {
        if (content->GetType() == "Bundle")
            delete dynamic_cast<Bundle*>(content);
        else
            delete content;
    }
}

std::string Bundle::Display(std::string indent) {
    std::string outputString = "";
    outputString += indent + "Title: " + this->GetTitle();
    outputString += "\n" + indent + "ISBN: " + std::to_string(this->GetISBN());
    outputString += "\n" + indent + "Genre: " + this->GetGenre();
    outputString += "\n" + indent + "Frequency: " + std::to_string(this->GetFrequency()) + "\n";
    for (Content* content : this->contentList)
        if (content->GetAuthor().size() != 0)
            outputString += content->Display(indent + "\t") + "\n";
    return outputString;
}