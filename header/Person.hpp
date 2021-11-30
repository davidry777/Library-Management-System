#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>
#include <string>

class BookSystem;

class Person {
    protected:
        std::string fullName;
        int ID;
        int password;
        BookSystem* bookSys;
    public:
        virtual ~Person() = default;
        std::string GetName() { return fullName; }
        int GetId() { return ID; }
        int GetHashedPassword() { return password; }
        BookSystem* GetBookSys() { return bookSys; }
        virtual void GetInfo() = 0;
        virtual std::string GetType() = 0;
};

#endif //__PERSON_HPP__
