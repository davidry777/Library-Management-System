#include "../header/GenreSearch.hpp"

std::vector<Content*> GenreSearch::SearchBooks(std::unordered_map<long long, Content*> catalogue, std::string genre)
{
	std::vector<Content*> foundBooks;
	std::vector<Content*> mapped = MapToVector(catalogue);
	foundBooks = SearchGenre(mapped, genre);
	return foundBooks;	
}
std::vector<Content*> GenreSearch::SearchBooks(std::vector<CheckOutData*> usercat, std::string genre)
{
	std::vector<Content*> foundBooks;
	std::vector<Content*> mapped = MapToVector(catalogue);
	foundBooks = SearchGenre(mapped, genre);
	return foundBooks;
}
std::vector<Content*> GenreSearch::SearchGenre(std::vector<Content*> catalogue, std::string genre)
{
	std::vector<Content*> tempFound;
	for (Content* c : catalogue)
	{
		if(c->getGenre().compare(genre) == 0)
		{
			tempFound.push_back(c);
		}
	}
	return tempFound;
}

