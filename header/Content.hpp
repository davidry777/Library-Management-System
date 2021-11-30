#pragma once
#include <string>
class Content {
    protected:
        std::string title;
        long long ISBN;
        std::string genre;
        int frequency;
        std::string author;
    public:
        Content(const std::string& title, long long ISBN, const std::string& genre, const std::string& author, int frequency = 0) : title(title), ISBN(ISBN), genre(genre), author(author), frequency(frequency) {}
        virtual std::string Display(std::string indent = "") = 0;
        void AddFrequency() { ++frequency; }

        std::string GetTitle() { return title; }
        long long GetISBN() { return ISBN; }
        std::string GetGenre() { return genre; }
        int GetFrequency() { return frequency; }
        virtual std::string GetAuthor() { return author; }
};
