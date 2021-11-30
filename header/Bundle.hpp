#pragma once

#include "Content.hpp"

#include <string>
#include <map>
#include <vector>
#include <iostream>

class Bundle : public Content {
    private:
        std::map<long long, Content*> contentList;
    public:
        Bundle(const std::string& title, long long ISBN, const std::string& genre, const std::vector<Content*>& contentList, int frequency = 0);
        ~Bundle();

        std::string GetAuthor();
        std::string Display(std::string indent = "");
        std::string GetType() { return "Bundle"; };
