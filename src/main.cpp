#pragma once

#include <iostream>
#include <string>
#include "../header/Book.hpp"
#include "../header/LoginSystem.hpp"

void PrintUserInfo(User* person) {
    person->GetInfo();
}

void CheckoutBook(User* person) {
    long long isbn = -1;

    std::cout << "Enter ISBN13 number to checkout out a book: " << std::endl;
    std::cin >> isbn;
    std::cout << std::endl;

    std::cout << "Checking Out Book..." << std::endl;
    person->CheckoutBook(isbn);
}

void ReturnBook(User* person) {
    long long isbn = -1;

    std::cout << "Enter ISBN13 number to return a book: " << std::endl;
    std::cin >> isbn;
    std::cout << std::endl;

    std::cout << "Returning book..." << std::endl;
    person->ReturnBook(isbn);
}

void ShowDebt(User* person) {
    std::cout << "Amount of debt: $" << person->GetBalance() << std::endl;
}

void PayDebt(User* person) {
    int money = 0;

    std::cout << "Enter how much money you want to pay off: " << std::endl;
    std::cin >> money;
    std::cout << std::endl;

    std::cout << "Paying off $" << money << std::endl;
    person->PayBalance(money);
}

void DisplayCheckedOutBooks(User* person) {
    std::cout << person->GetName() << "'s Checked Out Books:" << std::endl;
    person->DisplayCheckOut();
    std::cout << std::endl;
}

void PrintLibrarianInfo(Librarian* person) {
    person->GetInfo();
}

void AddBook(Librarian* person) {
    std::string title, genre, author;
    long long isbn;

    std::cout << "Enter title for new book: " << std::endl;
    std::cin >> title;
    std::cout << std::endl;
    std::cout << "Enter ISBN for " << title << ": " << std::endl;
    std::cin >> isbn;
    std::cout << std::endl;
    std::cout << "Enter genre for " << title << ": " << std::endl;
    std::cin >> genre;
    std::cout << std::endl;
    std::cout << "Enter author for " << title << ": " << std::endl;
    std::cin >> author;
    std::cout << std::endl;

    Book* newBook = new Book(title, isbn, genre, author, 0);
    std::cout << title << " added to Librarian " << person->GetName() << "'s library" << std::endl;
}

void RemoveBook(Librarian* person) {
    long long isbn = -1;

    std::cout << "Enter ISBN13 number to remove out a book: " << std::endl;
    std::cin >> isbn;
    std::cout << std::endl;

    std::cout << "Removing book..." << std::endl;
    person->RemoveBook(isbn);
}

void SetNewLibrary(Librarian* person, LibrarySystem* newLibrary) {
    person->SetLibrary(newLibrary);
}

bool Login() {
    return loggingIn.LoginVerify(id, password);
}

void PrintMenu(User* person) {
    std::cout << "/---------------- User Library Menu ----------------/" << std::endl;
    std::cout << "/           1. Display Your Information             /" << std::endl;
    std::cout << "/           2. Check Out a Book                     /" << std::endl;
    std::cout << "/           3. Return a Book                        /" << std::endl;
    std::cout << "/           4. Display Debt From Fines              /" << std::endl;
    std::cout << "/           5. Pay off Debt                         /" << std::endl;
    std::cout << "/           6. Show all Checked Out Books           /" << std::endl;
    std::cout << "/---------------------------------------------------/" << std::endl;
}

void PrintMenu(Librarian* person) {
    std::cout << "/------------- Librarian Library Menu --------------/" << std::endl;
    std::cout << "/           1. Display Your Information             /" << std::endl;
    std::cout << "/           2. Add Book to Library                  /" << std::endl;
    std::cout << "/           3. Remove Book from Library             /" << std::endl;
    std::cout << "/           4. Set a New Library                    /" << std::endl;
    std::cout << "/---------------------------------------------------/" << std::endl;
}

int main()
{
    LoginSystem loggingIn;

    int id;
    std::string password;
    std::cout << "Enter Your User ID: " << std::endl;
    std::cin >> id;
    std::cout << std::endl;

    std::cout << "Enter Password: " << std::endl;
    std::cin >> password;
    std::cout << std::endl;

    if(Login())
    {
        UserSystem* us;
        BookSystem* bs;
        LibrarySystem* library = new LibrarySystem(us, bs, "../catalogue.json", "../checked_out.json", "../passed_due.json");
        Person* person = library->GetUserSystem()->GetPerson(id);
        do {
            PrintMenu(person);
            
        }
        while
    }
    return 0;
}
