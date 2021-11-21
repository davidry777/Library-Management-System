#include "../header/Librarian.hpp"

Librarian::Librarian(std::string name, int id, LibrarySystem* set_library)
{ 
    fullName = name;
    ID = id;
    library = set_library;
}

void Librarian::AddBook(Book* newBook) { library->bookSystem->AddContent(newBook); }

void Librarian::RemoveBook(int ISBN) { library->bookSystem->RemoveContent(ISBN); }