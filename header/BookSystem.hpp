#ifndef __BOOKSYSTEM_HPP__
#define __BOOKSYSTEM_HPP__

#pragma once

#include <iostream>
#include <unordered_map>
#include <deque>
#include <ctime>

#include "Person.hpp"
#include "Content.hpp"

struct CheckOutData {
    time_t timeCheckedOut;
    Content* contentCheckedOut;
    Person* userCheckedOut;
    bool overTime;

    CheckOutData(time_t a, Content* b, Person* c) : timeCheckedOut(a), contentCheckedOut(b), userCheckedOut(c), overTime(false) {}
};

class BookSystem {
    private:
        std::unordered_map<int, Content*> catalogue;
        std::deque<CheckOutData*> checkedOut; 
    public:
        void AddContent(Content* content);
        void RemoveContent(int ISBN);

        CheckOutData* CheckOut(Person* person, int ISBN);
        bool ReturnContent(Person* person, int ISBN);
        void CheckExpiration();
};

#endif  //__BOOKSYSTEM_HPP__