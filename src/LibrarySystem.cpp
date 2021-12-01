#include "../header/LibrarySystem.hpp"

LibrarySystem::LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& passedDueFile, const std::string& peopleInput, const std::string& checkOut) {
    this->bookSystem = new BookSystem(catalogueFile, checkedOutFile);
    this->userSystem = new UserSystem(peopleInput, this->bookSystem);
    this->bookSystem->LoadCheckedOut(this->userSystem->GetMap());
    this->userSystem->AddCheckedOut(this->bookSystem->GetCheckedOut());
}

LibrarySystem::LibrarySystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& passedDueFile, const std::string& peopleInput, const std::string& checkOut, int checkoutTime) {
    this->bookSystem = new BookSystem(catalogueFile, checkedOutFile, checkoutTime);
    this->userSystem = new UserSystem(peopleInput, this->bookSystem);
    this->bookSystem->LoadCheckedOut(this->userSystem->GetMap());
    this->userSystem->AddCheckedOut(this->bookSystem->GetCheckedOut());
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
