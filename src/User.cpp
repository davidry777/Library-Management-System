#include "../header/User.hpp"
#include "../header/Person.hpp"
#include "../header/BookSystem.hpp"
#include "../header/DisplaySystem.hpp"

User::User(std::string name, int id, LibrarySystem* set_library) : Person(name, id, set_library), debt(0) { }

int User::GetBalance() { return debt; }

void User::PayBalance(int cash) { debt -= cash; }