#include "../header/BookSearch.h"

class ISBNSearch : public BookSearch
{
private:

public:
	std::vector<Book*> SearchBooks(std::vector<Book*>& catalogue, int ISBN)
	{
		std::vector<Book*> temp;
		temp = SearchGenre(catalogue, ISBN);
		return temp;
	}
	
	std::vector<Book*> SearchISBN(std::vector<Book*>& catalogue, int ISBN)
	{
		std::vector<Book*> tempFound;
		for(Book* b: catalogue)
		{
			if(b->GetISBN() == ISBN)
			{
				tempFound.push_back(b);
			}
		}
		return tempFound;
	}
}
