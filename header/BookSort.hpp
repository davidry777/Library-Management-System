#ifndef __BOOKSORT_H
#define __BOOKSORT_H
#include <vector>
#include <string>
#include "../src/Book.cpp"

class BookSort {
 private:

 public:
	virtual std::vector<Content*> SortBooks(std::unordered_map<int, Content*>) = 0;
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
