#ifndef __BOOKSORT_H
#define __BOOKSORT_H
#include <vector>
#include <string>
#include "../src/Book.cpp"

class BookSort {
 private:

 public:
	virtual std::vector<Content*> SortBooks(std::unordered_map<int, Content*>) = 0;
	virtual std::vector<Content*> SortBooks(std::vector<CheckOutData*>) = 0;
	std::vector<Content*> MapToVector(std::unordered_map<int, Content*> catalogue)
	{
		std::vector<Content*> mapped;
		for(auto i : catalogue)
		{
			mapped.push_back(i.second);
		}	
		return mapped;
	}
	std::vector<Content*> MapToVector(std::vector<CheckedOut*> usercat)
	{
		std::vector<Content*> mapped;
		for(CheckedOut* i : usercat)
		{
			mapped.push_back(i.contentCheckedOut);
		}
		return mapped;
	}
};
#endif
