#include "../header/BookSearch.hpp"

class GenreSearch : public BookSearch
{
 private:

 public:
	std::vector<Book*> SearchBooks(std::vector<Book*>& catalogue, std::string genre)
	{
		std::vector<Book*> foundBooks;
		temp = SearchGenre(catalogue, genre);
		return foundBooks;	
	}
	std::vector<Book*> SearchGenre(std::vector<Book*>& catalogue, std::string genre)
	{
		std::vector<Book*> tempFound;
		for (Book* b : catalogue)
		{
			if(b->getGenre().compare(genre) == 0)
			{
				tempFound.push_back(b);
			}
		}
		return tempFound;
	}
};
