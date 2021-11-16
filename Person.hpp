#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>
#include <string.h>

using namespace std;

class Person 
{
    protected:
        string fullName;
        int id;
        int hashedPassword;
        LibrarySystem* library;
        
        virtual ~Person() = default;
        virtual std::string GetName() = 0;
        virtual int GetId() = 0;
        virtual std::string CheckPerson(Person* person) = 0;
        virtual std::string GetInfo() = 0;
        virtual int GetHashedPassword() = 0;
        virtual std::string GetBookInfo() = 0;
};

#endif //__PERSON_HPP__