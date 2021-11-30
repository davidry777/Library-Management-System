#include "../header/Librarian.hpp"

Librarian::Librarian(std::string name, int id, LibrarySystem* set_library, int hashedPassword)
{ 
    fullName = name;
    ID = id;
    library = set_library;
    password = hashedPassword;
}

Librarian::~Librarian() { delete library; }

void Librarian::GetInfo()
{
    cout << "Name: " << fullName << endl;
    cout << "ID: " << ID << endl;
    cout << "Status: Librarian" << endl;
}

std::string Librarian::GetType() { return "Librarian"; }

void Librarian::AddBook(Book* newBook) { library->GetBookSystem()->AddContent(newBook); }

void Librarian::RemoveBook(long long ISBN) { library->GetBookSystem()->RemoveContent(ISBN); }

void Librarian::SetLibrary(LibrarySystem* newLibrary) { library = newLibrary; }
