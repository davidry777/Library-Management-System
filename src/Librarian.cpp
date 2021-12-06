#include "../header/Librarian.hpp"

using namespace std;

Librarian::Librarian(std::string name, int id, BookSystem* books, int hashedPassword)
{ 
    fullName = name;
    ID = id;
    bookSys = books;
    password = hashedPassword;
}

void Librarian::GetInfo()
{
    cout << "Name: " << fullName << endl;
    cout << "ID: " << ID << endl;
    cout << "Status: Librarian" << endl;
}

std::string Librarian::GetType() { return "Librarian"; }

void Librarian::AddBook(Book* newBook) { bookSys->AddContent(newBook); }

void Librarian::RemoveBook(long long ISBN) { bookSys->RemoveContent(ISBN); }

void Librarian::SetBookSys(BookSystem* newBookSys) { bookSys = newBookSys; }

void Librarian::PrintCatalogue() 
 { 
     DisplaySystem catOutput = DisplaySystem();
     catOutput.DisplayBooks(bookSys->GetCatalogue());
 }
