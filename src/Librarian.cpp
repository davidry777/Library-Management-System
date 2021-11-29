#include "../header/Librarian.hpp"

Librarian::Librarian(std::string name, int id, LibrarySystem* set_library, std::string hashedPassword)
{ 
    fullName = name;
    ID = id;
    library = set_library;
    password = hashedPassword
}

void Librarian::AddBook(Book* newBook) { library->bookSystem->AddContent(newBook); }

void Librarian::RemoveBook(int ISBN) { library->bookSystem->RemoveContent(ISBN); }

void Librarian::SetLibrary(LibrarySystem* newLibrary) { library = newLibrary; }