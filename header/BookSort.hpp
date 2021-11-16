#ifndef __BOOKSORT_H
#define __BOOKSORT_H
#include <vector>
#include <string>
#include "Book.hpp"

class BookSort {
 private:

 public:
	virtual std::vector<Book*>& SortBooks(std::vector<Book*>&) = 0;
};
#endif
