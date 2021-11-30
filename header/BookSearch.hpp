#ifndef __BOOKSEARCH_H
#define __BOOKSEARCH_H
#include <vector>
#include <string>
#include "Book.hpp"
#include "BookSystem.hpp"
#include "CheckOutData.hpp"

class BookSearch {
 private:

 public:
	std::vector<Content*> SearchBooks(std::unordered_map<long long, Content*>, std::string);
	std::vector<Content*> SearchBooks(std::unordered_map<long  long, Content*>, int);
	std::vector<Content*> SearchBooks(std::vector<CheckOutData*>, std::string);
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
