#include "../header/Book.hpp"

Book::Book(std::string title, int ISBN, std::string author, std::string genre, std::string subgrenre) : Content(title, ISBN), author(author), genre(genre), subgenre(subgenre), frequency(0) {}

std::string Book::GetAuthor() { return this->author; }
std::string Book::GetGenre() { return this->genre; }
std::string Book::GetSubgenre() { return this->subgenre; }
int Book::GetFrequency() { return this->frequency; }

void Book::Display() {
    std::cout << "Title: " << this->title;
    std::cout << "\nISBN: " << this->ISBN;
    std::cout << "\nAuthor: " << this->author;
    std::cout << "\nGenre: " << this->genre;
    std::cout << "\nSubGenre: " << this->subgenre;
    std::cout << "\nFrequency: " << this->frequency;
}