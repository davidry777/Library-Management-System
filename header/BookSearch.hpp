#ifndef __BOOKSEARCH_HPP__
#define __BOOKSEARCH_HPP__

#include <vector>
#include <string>
#include "Book.hpp"

class BookSearch {
 private:

 public:
	virtual std::vector<Book*> SearchBooks(std::vector<Book*>, std::string) = 0;
};
#endif
