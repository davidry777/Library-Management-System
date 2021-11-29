#include "../header/BookSearch.hpp"

class KeyWordSearch : public BookSearch
{
private:

public:
	std::vector<Content*> SearchBooks(std::unordered_map<int, Content*> catalogue, std::string keyword)
	{
		std::vector<Content*> foundBooks;
		std::vector<Content*> mapped = MapToVector(catalogue);
		foundBooks = SearchKeyWord(mapped, keyword);
		return foundBooks;
	}

	std::vector<Content*> SearchBooks(std::vector<CheckOutData*> usercat, std::string keyword)
	{
		std::vector<Content*> foundBooks;
		std::vector<Content*> mapped = MapToVector(usercat);
		foundBooks = SearchKeyWord(mapped, keyword);
		return foundBooks;
	}

	std::vector<Content*> SearchKeyWord(std::vector<Content*> catalogue, std::string keyword)
	{
		std::vector<Content*> tempFound;
		for(Content* c : catalogue)
		{
			std::size_t found = c->getTitle().find(keyword);
			if(found != std::string::npos)
				tempFound.push_back(c);
		}
		return tempFound;
	}
};
