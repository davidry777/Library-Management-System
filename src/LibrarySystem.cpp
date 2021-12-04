#include "../header/LibrarySystem.hpp"

LibrarySystem::LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& peopleInput) {
    this->bookSystem = BookSystem(catalogueFile, checkedOutFile);
    this->userSystem = UserSystem(peopleInput, &this->bookSystem);
    this->bookSystem.LoadCheckedOut(this->userSystem.GetMap());
    this->userSystem.AddCheckedOut(this->bookSystem.GetCheckedOut());
}

LibrarySystem::LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& peopleInput, int checkoutTime) {
    this->bookSystem = BookSystem(catalogueFile, checkedOutFile, checkoutTime);
    this->userSystem = UserSystem(peopleInput, &this->bookSystem);
    this->bookSystem.LoadCheckedOut(this->userSystem.GetMap());
    this->userSystem.AddCheckedOut(this->bookSystem.GetCheckedOut());
}

UserSystem LibrarySystem::GetUserSystem() {
    return this->userSystem;
}

BookSystem LibrarySystem::GetBookSystem() {
    return this->bookSystem;
}
