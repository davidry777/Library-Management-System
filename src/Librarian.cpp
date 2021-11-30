#include "../header/Librarian.hpp"

Librarian::Librarian(std::string name, int id, LibrarySystem* set_library, std::string hashedPassword)
{ 
    fullName = name;
    ID = id;
    library = set_library;
    password = hashedPassword;
}

void Librarian::AddBook(Book* newBook) { library->GetBookSystem()->AddContent(newBook); }

void Librarian::RemoveBook(int ISBN) { library->GetBookSystem()->RemoveContent(ISBN); }

void Librarian::SetLibrary(LibrarySystem* newLibrary) { library = newLibrary; }