#include "../header/Librarian.hpp"

Librarian::Librarian(std::string name, int id, BookSystem* books, int hashedPassword)
{ 
    fullName = name;
    ID = id;
    bookSys = books;
    password = hashedPassword;
}

Librarian::~Librarian() { delete bookSys; }

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
