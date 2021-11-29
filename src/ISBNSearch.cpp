#include "../header/BookSearch.h"

class ISBNSearch : public BookSearch
{
private:

public:
	std::vector<Content*> SearchBooks(std::unordered_map<int, Content*> catalogue, int ISBN)
	{
		std::vector<Content*> temp;
		std::vector<Content*> mapped = MapToVector(catalogue);
		temp = SearchGenre(mapped, ISBN);
		return temp;
	}
	
	std::vector<Content*> SearchISBN(std::vector<Content*> catalogue, int ISBN)
	{
		std::vector<Content*> tempFound;
		for(Content* c: catalogue)
		{
			if(c->GetISBN() == ISBN)
			{
				tempFound.push_back(c);
				return tempFound;
			}
		}
		return tempFound;
	}
}
