#ifndef __LIBRARIAN_HPP__
#define __LIBRARIAN_HPP__

#include "Person.hpp"
#include "BookSystem.hpp"
#include "LibrarySystem.hpp"
#include "Book.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class LibrarySystem;

class Librarian : public Person {
    public:
        Librarian(std::string name, int id, LibrarySystem* set_library, int hashedPassword);
        ~Librarian();
        void GetInfo();
        std::string GetType();
        void AddBook(Book* newBook);
        void RemoveBook(long long ISBN);
        void SetLibrary(LibrarySystem* newLibrary);
};

#endif //__LIBRARIAN_HPP__
