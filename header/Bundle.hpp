#pragma once

#include "Content.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

class Bundle : public Content {
    private:
        std::vector<Content*> contentList;
    public:
        Bundle(const std::string& title, long long ISBN, const std::string& genre, const std::vector<Content*>& list, int frequency = 0);

        Bundle(std::string t, long long i, std::string g, std::vector<Content*>& list);
        ~Bundle();

        std::string GetAuthor();
        std::string Display(std::string indent = "");
        std::string GetType() { return "Bundle"; }
};