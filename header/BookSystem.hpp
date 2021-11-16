#pragma once

#include <iostream>
#include <unordered_map>
#include <queue>
#include <ctime>

#include "Content.hpp"

class BookSystem {
    private:
        std::unordered_map<int, Content*> catalogue;
        std::queue<std::pair<std::time_t, Content*>> checkedOut; 
    public:
        void AddContent(Content* content);
        void RemoveContent(int ISBN);

        std::pair<std::time_t, Content*> CheckOut(int ISBN);
};