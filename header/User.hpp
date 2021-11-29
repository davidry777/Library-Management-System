#ifndef __USER_HPP__
#define __USER_HPP__

#include <iostream>
#include <string.h>
#include <vector>
#include <time.h>

#include "Person.hpp"
#include "DisplaySystem.hpp"
#include "BookSystem.hpp"

class User : public Person
{
    private:
        std::vector<CheckOutData*> checkedOut;
        int debt;

    public:
        User(std::string name, int id, LibrarySystem* set_library);
        ~User();
        int GetBalance();
        void PayBalance(int cash);
        void DisplayCheckOut();
        void SetCheckedOutData(vector<CheckOutData*> data);
};

#endif //__USER_HPP__