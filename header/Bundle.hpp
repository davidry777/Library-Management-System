#pragma once

#include "Content.hpp"

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class Bundle : public Content {
    private:
        std::unordered_map<int, Content*> contentList;
    public:
        Bundle(const std::string& title, int ISBN, const std::string& genre, const std::string& subgenre, const std::vector<Content*>& contentList = {});
        ~Bundle();

        void Display(std::string indent = "");
};