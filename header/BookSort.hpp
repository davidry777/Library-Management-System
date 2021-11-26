#ifndef __BOOKSORT_HPP__
#define __BOOKSORT_HPP__

#include <vector>
#include <string>
#include "Book.hpp"

class BookSort {
 private:

 public:
	virtual std::vector<Book*> SortBooks(std::vector<Book*>) = 0;
};

#endif	//__BOOKSORT_HPP__
