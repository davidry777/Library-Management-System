#ifndef __BOOKSORT_H
#define __BOOKSORT_H
#include "Book.hpp"
#include "BookSystem.hpp"
#include "CheckOutData.hpp"

class BookSort {
 private:

 public:
	virtual std::vector<Content*> SortBooks(std::unordered_map<long long, Content*>) = 0;
	virtual std::vector<Content*> SortBooks(std::vector<CheckOutData*>) = 0;
	std::vector<Content*> MapToVector(std::unordered_map<long long, Content*> catalogue)
	{
		std::vector<Content*> mapped;
		for(auto i : catalogue)
		{
			mapped.push_back(i.second);
		}	
		return mapped;
	}
	std::vector<Content*> MapToVector(std::vector<CheckOutData*> usercat)
	{
		std::vector<Content*> mapped;
		for(CheckOutData* i : usercat)
		{
			mapped.push_back(i->contentCheckedOut);
		}
		return mapped;
	}
};
#endif
