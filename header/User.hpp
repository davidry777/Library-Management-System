#ifndef __USER_HPP__
#define __USER_HPP__

#include "Person.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "DisplaySystem.hpp"
#include "BookSystem.hpp"
#include "CheckOutData.hpp"

using namespace std;

class User : public Person {
    private:
        int debt;
    public:
        User(std::string name, int id, BookSystem* books, int hashedPassword);
        void GetInfo();
        std::string GetType();
        void CheckoutBook(long long ISBN);
        void ReturnBook(long long ISBN);
        int GetBalance();
        void PayBalance(int cash);
        void DisplayCheckOut();
};

#endif //__USER_HPP__
