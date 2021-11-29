#include "../header/Book.hpp"

std::string Book::GetAuthor() { return this->author; }

Book::Book(const std::string& title, int ISBN, const std::string& genre, const std::string& author) : Content(title, ISBN, genre), author(author) {}

std::string Book::Display(std::string indent) {
    return "Title: " + this->title + "\nISBN: " + std::to_string(this->ISBN) + "\nAuthor: " + this->author + "\nGenre: " + this->genre + "\nFrequency: " + std::to_string(this->frequency);
}