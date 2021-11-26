#ifndef __BOOK_HPP__
#define __BOOK_HPP__

#pragma once

#include "Content.hpp"

#include <string>
#include <iostream>

class Book : public Content {
    private:
        std::string author;
        std::string genre;
        std::string subgenre;
        int frequency;
    public:
        Book(std::string title, int ISBN, std::string author,
             std::string genre, std::string subgrenre);
        std::string GetAuthor();
        std::string GetGenre();
        std::string GetSubgenre();
        int GetFrequency();
        void Display();
};

#endif  //__BOOK_HPP__