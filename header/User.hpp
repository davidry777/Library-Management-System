#ifndef __USER_HPP__
#define __USER_HPP__

#include "Person.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "LibrarySystem.hpp"
// #include "DisplaySystem.hpp"
#include "BookSystem.hpp"
#include "CheckOutData.hpp"

using namespace std;

class LibrarySystem;

class User : public Person {
    private:
        std::vector<CheckOutData*> checkedOut;
        int debt;
    public:
        User(std::string name, int id, LibrarySystem* set_library, int hashedPassword);
        ~User();
        void GetInfo();
        void CheckoutBook(long long ISBN);
        void ReturnBook(long long ISBN);
        int GetBalance();
        void PayBalance(int cash);
        void DisplayCheckOut();
        void SetCheckedOutData(vector<CheckOutData*> data);
};

#endif //__USER_HPP__
