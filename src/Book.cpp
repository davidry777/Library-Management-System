#include "../header/Book.hpp"

Book::Book(const std::string& title, long long ISBN, const std::string& genre, const std::string& author, int frequency) : Content(title, ISBN, genre, author, frequency) {}

std::string Book::Display(std::string indent) {
    return "Title: " + this->title + "\nISBN: " + std::to_string(this->ISBN) + "\nAuthor: " + this->author + "\nGenre: " + this->genre + "\nFrequency: " + std::to_string(this->frequency);
}