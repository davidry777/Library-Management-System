#include "../header/Book.hpp"

Book::Book(const std::string& title, long long ISBN, const std::string& genre, const std::string& author, int frequency) : Content(title, ISBN, genre, author, frequency) {}

std::string Book::Display(std::string indent) {
    return indent + "Title: " + this->title + "\n" + indent + "ISBN: " + std::to_string(this->ISBN) + "\n" + indent + "Author: " + this->author + "\n" + indent + "Genre: " + this->genre + "\n" + indent + "Frequency: " + std::to_string(this->frequency);
}