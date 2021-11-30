#include "../header/LibrarySystem.hpp"

LibrarySystem::LibrarySystem(UserSystem* us, BookSystem* bs, const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& passedDueFile, const std::string& peopleInput, const std::string& checkOut) : userSystem(us), bookSystem(bs) {
    this->bookSystem = new BookSystem(catalogueFile, checkedOutFile, passedDueFile);
    this->userSystem = new UserSystem(peopleInput, checkOut, bookSystem->GetPassedDue(), bookSystem->GetCheckedOut(), this->bookSystem);
    this->bookSystem->LoadCheckedOut(this->userSystem->GetMap());
    this->bookSystem->LoadPassedDue(this->userSystem->GetMap());
}

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
