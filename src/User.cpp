#include "../header/User.hpp"

using namespace std;

User::User(std::string name, int id, BookSystem* books, int hashedPassword) : debt(0)
{ 
    fullName = name;
    ID = id;
    bookSys = books;
    password = hashedPassword;
}

void User::GetInfo()
{
    cout << "Name: " << fullName << endl;
    cout << "ID: " << ID << endl;
    cout << "Status: User" << endl;
    cout << "Debt: $" << debt << endl;
}

std::string User::GetType() { return "User"; }

void User::CheckoutBook(long long ISBN) { bookSys->CheckOut(this, ISBN); }

void User::ReturnBook(long long ISBN) { bookSys->ReturnContent(this, ISBN); }

int User::GetBalance() { return debt; }

void User::PayBalance(int cash) { debt -= cash; }

void User::DisplayCheckOut()
{
    // DisplaySystem checkoutOutput = DisplaySystem();
    // checkoutOutput.DisplayBooks(checkedOut);
}

void User::SetCheckedOutData(vector<CheckOutData*> data) { this->checkedOut = data; }

vector<CheckOutData*> User::GetCheckedOut() { return checkedOut; }

void User::AddCheckOutData(CheckOutData* newCheckedOutBook) { checkedOut.push_back(newCheckedOutBook); }