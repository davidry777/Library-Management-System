#ifndef __BOOKSEARCH_H
#define __BOOKSEARCH_H
#include <vector>
#include <string>
#include "Book.hpp"

class BookSearch {
 private:

 public:
	virtual std::vector<Content*> SearchBooks(std::unordered_map<int, Content*>, std::string);
	std::vector<Content*> MapToVector(std::unordered_map<int, Content*> catalogue)
	{
		std::vector<Content*> mapped;
		for(auto i : catalogue)
		{
			mapped.push_back(i.second);	
		}
		return mapped;
	}
};
#endif
