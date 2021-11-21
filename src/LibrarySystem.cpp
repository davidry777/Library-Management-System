#include "../header/LibrarySystem.hpp"

LibrarySystem::LibrarySystem(UserSystem* us, BookSystem* bs) : userSystem(us), bookSystem(bs) {}

LibrarySystem::~LibrarySystem() {
    delete this->userSystem;
    delete this->bookSystem;
}

UserSystem* GetUserSystem() {
    return this->userSystem;
}

BookSystem* GetBookSystem() {
    return this->bookSystem;
}
