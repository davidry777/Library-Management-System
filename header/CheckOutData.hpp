#pragma once
#ifndef __CHECKOUTDATA_HPP__
#define __CHECKOUTDATA_HPP__

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
    bool operator<(const CheckOutData& rhs) const {
        return this->timeCheckedOut < rhs.timeCheckedOut;
    }
    bool operator==(const CheckOutData& rhs) const {
        return this->timeCheckedOut == rhs.timeCheckedOut && this->overTime == rhs.overTime && this->timeCheckedOut == rhs.timeCheckedOut && this->userCheckedOut == rhs.userCheckedOut;
    }
};

#endif	//__CHECKOUTDATA_HPP__
