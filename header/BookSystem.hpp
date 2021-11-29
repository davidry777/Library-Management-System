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
    int SecondsPassed() { return time(0) - timeCheckedOut; }
};

class BookSystem {
    private:
        std::unordered_map<int, Content*> catalogue;
        std::vector<CheckOutData*> passedDue;
        std::deque<CheckOutData*> checkedOut; 
    public:
        BookSystem();
        ~BookSystem();
        Content* GetContent(int ISBN);

        bool AddContent(Content* content);
        bool RemoveContent(int ISBN);

        CheckOutData* CheckOut(Person* person, int ISBN);
        bool ReturnContent(Person* person, int ISBN);
        void CheckExpiration();
};