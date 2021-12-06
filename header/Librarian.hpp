#ifndef __LIBRARIAN_HPP__
#define __LIBRARIAN_HPP__

#include "Person.hpp"
#include "BookSystem.hpp"
#include "Book.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Librarian : public Person {
    public:
        Librarian(std::string name, int id, BookSystem* books, int hashedPassword);
        void GetInfo();
        std::string GetType();
        void AddBook(Book* newBook);
        void RemoveBook(long long ISBN);
        void SetBookSys(BookSystem* newBookSys);
};

#endif //__LIBRARIAN_HPP__
