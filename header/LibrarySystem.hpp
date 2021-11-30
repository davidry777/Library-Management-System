#pragma once

#include "UserSystem.hpp"
#include "BookSystem.hpp"

class UserSystem;
class LibrarySystem;
class BookSystem;

class LibrarySystem {
    private:
        UserSystem* userSystem;
        BookSystem* bookSystem;
    public:
        LibrarySystem(UserSystem* us, BookSystem* bs, const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& passedDueFile, const std::string& peopleInput, const std::string& checkOut);
        ~LibrarySystem();
        UserSystem* GetUserSystem();
        BookSystem* GetBookSystem();
};
