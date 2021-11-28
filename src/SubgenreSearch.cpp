#include "../header/BookSearch.h"

class SubgenreSearch : public BookSearch
{
private:

public:
	std::vector<Book*> SearchBooks(std::vector<Book*> catalogue, std::string subgenre)
	{
		std::vector<Content*> temp;
		std::vector<Content*> mapped = MapToVector(catalogue);
		temp = SearchGenre(mapped, subgenre);
		return temp;
	}
	
	std::vector<Book*> SearchSubgenre(std::vector<Book*> catalogue, std::string subgenre)
	{
		std::vector<Book*> tempFound;
		for(Content* c : catalogue)
		{
			if(c->GetSubgenre().compare(subgenre) == 0)
			{
				tempFound.push_back(c);
			}
		}
		return tempFound;
	}
}
