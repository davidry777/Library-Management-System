#ifndef __LIBRARIAN_HPP__
#define __LIBRARIAN_HPP__

#include <iostream>
#include <string.h>
#include <vector>
#include <time.h>

#include "Person.hpp"
#include "BookSystem.hpp"
#include "LibrarySystem.hpp"
#include "Book.hpp"

class Librarian : public Person
{
    public:
        Librarian(std::string name, int id, LibrarySystem* set_library, int hashedPassword);
        ~Librarian();
        void GetInfo();
        void AddBook(Book* newBook);
        void RemoveBook(int ISBN);
        void SetLibrary(LibrarySystem* newLibrary);
};

#endif //__LIBRARIAN_HPP__
