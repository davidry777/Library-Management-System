#pragma once

#include <iostream>
#include "../header/LibrarySystem.hpp"
#include "../header/Book.hpp"

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
    std::cout << person->
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

void PrintMenu() {
    
}

int main() {

}
