#include "../header/User.hpp"

User::User(std::string name, int id, LibrarySystem* set_library) : debt(0)
{ 
    fullName = name;
    ID = id;
    library = set_library;
}

int User::GetBalance() { return debt; }

void User::PayBalance(int cash) { debt -= cash; }

std::vector<CheckOutData*> User::getCheckedOutList() { return checkedOut; }

void User::DisplayCheckOut()
{
    DisplaySystem checkoutOutput = DisplaySystem();
    checkoutOutput.DisplayBooks(checkedOut);
}