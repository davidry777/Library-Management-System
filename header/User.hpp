#ifndef __USER_HPP__
#define __USER_HPP__

#include <iostream>
#include <string.h>
#include <vector>
#include <time.h>

#include "Person.hpp"
#include "Book.hpp"

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
};

#endif //__USER_HPP__