#pragma once

#include "Content.hpp"

#include <string>
#include <iostream>

class Book : public Content {
    public:
        Book(const std::string& title, long long ISBN, const std::string& genre, const std::string& author, int frequency = 0);
        std::string Display(std::string indent = "");
};