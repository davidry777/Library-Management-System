#ifndef __BUNDLE_HPP__
#define __BUNDLE_HPP__

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
        Bundle(std::string title, int ISBN, const std::vector<Content*>& contentList = {});
        ~Bundle();

        void Display();
};