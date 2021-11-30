#pragma once

#include "UserSystem.hpp"
#include "BookSystem.hpp"

class LibrarySystem {
    private:
        UserSystem* userSystem;
        BookSystem* bookSystem;
    public:
        LibrarySystem(UserSystem* us, BookSystem* bs);
        ~LibrarySystem();
        UserSystem* GetUserSystem();
        BookSystem* GetBookSystem();
};