#include "../header/Book.hpp"

Book::Book(const std::string& title, int ISBN, const std::string& genre, const std::string& subgenre, const std::string& author) : Content(title, ISBN, genre, subgenre), author(author) {}

void Book::Display(std::string indent) {
    std::cout << "Title: " << this->title;
    std::cout << "\nISBN: " << this->ISBN;
    std::cout << "\nAuthor: " << this->author;
    std::cout << "\nGenre: " << this->genre;
    std::cout << "\nSubGenre: " << this->subgenre;
    std::cout << "\nFrequency: " << this->frequency;
}