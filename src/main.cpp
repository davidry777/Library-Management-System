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

bool Login(int id, std::string &password, LoginSystem *logSys) {
    return logSys->LoginVerify(id, password);
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

int SwitchCase(User* person)
{
    int input = -1;
    std::cout << "Type an option (1-6). Type -1 to quit: ";
    std::cin >> input;
    std::cout << std::endl;

    switch(input)
    {
        case '1':
            PrintUserInfo(person);
        case '2':
            CheckoutBook(person);
        case '3':
            ReturnBook(person);
        case '4':
            ShowDebt(person);
        case '5':
            PayDebt(person);
        case '6':
            DisplayCheckedOutBooks(person);
    }

    return input;
}

int SwitchCase(Librarian* librarian)
{
    int input = -1;
    std::cout << "Type an option (1-4). Type -1 to quit: ";
    std::cin >> input;
    std::cout << std::endl;

    switch(input)
    {
        case '1':
            PrintLibrarianInfo(librarian);
        case '2':
            AddBook(librarian);
        case '3':
            RemoveBook(librarian);
        case '4':
            /*new library catalogue and checked out and passed out as input string
            use us and bs
            
            LibrarySystem* lib = new LibrarySystem(us, bs, newCat, newCheckOut);*/
    }

    return input;
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

    LoginSystem* logSys = new LoginSystem("userLogins.txt");

    if(Login(id,password, logSys))
    {
        UserSystem* us;
        BookSystem* bs;
        LibrarySystem* library = new LibrarySystem(us, bs, "../catalogue.json", "../checked_out.json", "../passed_due.json");
        Person* person = library->GetUserSystem()->GetPerson(id);
        
        if (person->GetType() == "User"){
            User* user = dynamic_cast<User*>(person);
            int option = -1;
            do {
                PrintMenu(user);
                int option = SwitchCase(user);
            } while (option != -1);
        }    
        else
        {
            Librarian* librarian = dynamic_cast<Librarian*>(person);
            int option = -1;
            do {
                PrintMenu(librarian);
                int option = SwitchCase(librarian);
            } while (option != -1);
        }
    }
    return 0;
}