#include "../header/LibrarySystem.hpp"

LibrarySystem::LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& peopleInput) {
    this->bookSystem = BookSystem(catalogueFile, checkedOutFile);
    this->userSystem = UserSystem(peopleInput, &this->bookSystem);
    this->bookSystem.LoadCheckedOut(this->userSystem.GetMap());
}

LibrarySystem::LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& peopleInput, int checkoutTime) {
    this->bookSystem = BookSystem(catalogueFile, checkedOutFile, checkoutTime);
    this->userSystem = UserSystem(peopleInput, &this->bookSystem);
    this->bookSystem.LoadCheckedOut(this->userSystem.GetMap());
}

UserSystem LibrarySystem::GetUserSystem() {
    return this->userSystem;
}

BookSystem LibrarySystem::GetBookSystem() {
    return this->bookSystem;
}
