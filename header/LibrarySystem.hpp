#pragma once

#include "UserSystem.hpp"
#include "BookSystem.hpp"

class LibrarySystem {
    private:
        UserSystem* userSystem;
        BookSystem* bookSystem;
    public:
        LibrarySystem(UserSystem* us, BookSystem* bs, const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& passedDueFile);
        ~LibrarySystem();
        UserSystem* GetUserSystem();
        BookSystem* GetBookSystem();
};