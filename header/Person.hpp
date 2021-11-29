#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>
#include <string>

using namespace std;

class Person 
{
    protected:
        string fullName;
        int ID;
    
    public:
        virtual ~Person() = default;
        std::string GetName() { return fullName; }
        int GetId() { return ID; }
        virtual std::string CheckPerson(Person* person) = 0;
        virtual std::string GetInfo() = 0;
        virtual std::string GetBookInfo() = 0;
};

#endif //__PERSON_HPP__