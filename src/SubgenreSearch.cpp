#include "../header/BookSearch.h"

class SubgenreSearch : public BookSearch
{
private:

public:
	std::vector<Book*> SearchBooks(std::vector<Book*>& catalogue, std::string subgenre)
	{
		std::vector<Book*> temp;
		temp = SearchGenre(catalogue, subgenre);
		return temp;
	}
	
	std::vector<Book*> SearchSubgenre(std::vector<Book*>& catalogue, std::string subgenre)
	{
		std::vector<Book*> tempFound;
		for(Book* b : catalogue)
		{
			if(b->GetSubgenre().compare(subgenre) == 0)
			{
				tempFound.push_back(b);
			}
		}
		return tempFound;
	}
}
