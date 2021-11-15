#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>
#include <string>

using namespace std;

class Person 
{
    protected:
        string fullName;
        int id;
        int hashedPassword;
        LibrarySystem* library;
        
        string GetName();
        int GetId();
        string CheckPerson(Person*);
        string GetInfo();
        int GetHashedPassword();
        string GetBookInfo();
};

#endif //__PERSON_HPP__