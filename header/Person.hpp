#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>
#include <string>

//#include "LibrarySystem.hpp"

class Person 
{
    protected:
        std::string fullName;
        int ID;
        std::string password;
    
    public:
        virtual ~Person() = default;
        std::string GetName() { return fullName; }
        int GetId() { return ID; }
        std::string GetHashedPassword() { return password; }
        virtual std::string CheckPerson(Person* person) = 0;
        virtual std::string GetInfo() = 0;
        virtual std::string GetBookInfo() = 0;
};

#endif //__PERSON_HPP__
