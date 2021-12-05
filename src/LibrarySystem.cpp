#include "../header/LibrarySystem.hpp"

LibrarySystem::LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& peopleInput) {
    this->bookSystem = new BookSystem(catalogueFile, checkedOutFile);
    this->userSystem = new UserSystem(peopleInput, this->bookSystem);
    this->bookSystem->LoadCheckedOut(this->userSystem->GetMap());
}

LibrarySystem::LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& peopleInput, int checkoutTime) {
    this->bookSystem = new BookSystem(catalogueFile, checkedOutFile, checkoutTime);
    this->userSystem = new UserSystem(peopleInput, this->bookSystem);
    this->bookSystem->LoadCheckedOut(this->userSystem->GetMap());
}

LibrarySystem::~LibrarySystem() {
    delete userSystem;
    delete bookSystem;
}

UserSystem* LibrarySystem::GetUserSystem() {
    return this->userSystem;
}

BookSystem* LibrarySystem::GetBookSystem() {
    return this->bookSystem;
}
