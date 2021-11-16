#ifndef __BOOKSEARCH_H
#define __BOOKSEARCH_H
#include <vector>
#include <string>
#include "Book.hpp"

class BookSearch {
 private:

 public:
	virtual std::vector<Book*>& SearchBooks(std::vector<Book*>&) = 0;
};
#endif
