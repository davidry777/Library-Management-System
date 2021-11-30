#include "../header/User.hpp"

User::User(std::string name, int id, LibrarySystem* set_library, std::string hashedPassword) : debt(0)
{ 
    fullName = name;
    ID = id;
    library = set_library;
    password = hashedPassword;
}

User::~User()
{
    delete library;
}

void User::CheckoutBook(long long ISBN) { library->GetBookSystem()->CheckOut(this, ISBN); }

void User::ReturnBook(long long ISBN) { library->GetBookSystem()->ReturnContent(this, ISBN); }

int User::GetBalance() { return debt; }

void User::PayBalance(int cash) { debt -= cash; }

void User::DisplayCheckOut()
{
    DisplaySystem checkoutOutput = DisplaySystem();
    checkoutOutput.DisplayBooks(checkedOut);
}

void User::SetCheckedOutData(vector<CheckOutData*> data) { this->checkedOut = data; }