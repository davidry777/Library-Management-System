#include "../header/LibrarySystem.hpp"

LibrarySystem::LibrarySystem(UserSystem* us, BookSystem* bs) : userSystem(us), bookSystem(bs) {}

LibrarySystem::~LibrarySystem() {
    delete this->userSystem;
    delete this->bookSystem;
}

UserSystem* LibrarySystem::GetUserSystem() {
    return this->userSystem;
}

BookSystem* LibrarySystem::GetBookSystem() {
    return this->bookSystem;
}
