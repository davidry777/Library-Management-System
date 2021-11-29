#pragma once
#include <string>
class Content {
    protected:
        std::string title;
        int ISBN;
        std::string genre;
        int frequency;
    public:
        Content(const std::string& title, int ISBN, const std::string& genre) : title(title), ISBN(ISBN), genre(genre), frequency(0) {}
        virtual std::string Display(std::string indent = "") = 0;
        void AddFrequency() { ++frequency; }

        std::string GetTitle() { return title; }
        int GetISBN() { return ISBN; }
        std::string GetGenre() { return genre; }
        int GetFrequency() { return frequency; }
};