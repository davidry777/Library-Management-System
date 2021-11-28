#pragma once

#include <string>

class Content {
    protected:
        std::string title;
        int ISBN;
        std::string genre;
        std::string subgenre;
        int frequency;
    public:
        Content(const std::string& title, int ISBN, const std::string& genre, const std::string& subgenre) : title(title), ISBN(ISBN), genre(genre), subgenre(subgenre), frequency(0) {}
        virtual void Display(std::string indent = "") = 0;

        std::string GetTitle() { return title; }
        int GetISBN() { return ISBN; }
        std::string GetGenre() { return genre; }
        std::string GetSubgenre() { return subgenre; }
        int GetFrequency() { return frequency; }
};