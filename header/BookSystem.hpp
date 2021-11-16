#pragma once

#include <iostream>
#include <unordered_map>
#include <queue>
#include <ctime>

#include "Content.hpp"

class BookSystem {
    private:
        std::unordered_map<int, Content*> catalogue;
    public:
        void AddContent(Content* content);
        void RemoveContent(int ISBN);
};