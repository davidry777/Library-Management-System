#pragma once

#include <ctime>
#include "Content.hpp"
#include "Person.hpp"

class Person;

struct CheckOutData {
    time_t timeCheckedOut;
    Content* contentCheckedOut;
    Person* userCheckedOut;
    bool overTime;

    CheckOutData(time_t a, Content* b, Person* c, bool overTime = false) : timeCheckedOut(a), contentCheckedOut(b), userCheckedOut(c), overTime(false) {}
};
