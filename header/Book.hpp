#pragma once

#include "Content.hpp"

#include <string>
#include <iostream>

class Book : public Content {
    private:
        std::string author;
    public:
        Book(const std::string& title, int ISBN, const std::string& genre, const std::string& author);
        std::string GetAuthor();
        void Display(std::string indent = "");
};