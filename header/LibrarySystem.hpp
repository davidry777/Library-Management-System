#pragma once
#ifndef __LIBRARYSYSTEM_HPP__
#define __LIBRARYSYSTEM_HPP__

#include "UserSystem.hpp"
#include "BookSystem.hpp"

class UserSystem;
class LibrarySystem;
class BookSystem;

class LibrarySystem {
    private:
        UserSystem userSystem;
        BookSystem bookSystem;
    public:
        LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& peopleInput);
        LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& peopleInput, int checkoutTime);
        ~LibrarySystem();
        UserSystem GetUserSystem();
        BookSystem GetBookSystem();
};

#endif
