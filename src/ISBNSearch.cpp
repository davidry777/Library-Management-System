#include "../header/ISBNSearch.hpp"

std::vector<Content*> ISBNSearch::SearchBooks(std::unordered_map<long long, Content*> catalogue, long long ISBN)
{
	std::vector<Content*> temp;
	std::vector<Content*> mapped = MapToVector(catalogue);
	temp = SearchGenre(mapped, ISBN);
	return temp;
}
std::vector<Content*> ISBNSearch::SearchBooks(std::vector<CheckOutData*> usercat, long long ISBN)
{
	std::vector<Content*> temp;
	std::vector<Content*> mapped = MapToVector(usercat);
	temp = SearchGenre(mapped, ISBN);
	return temp;
}
std::vector<Content*> ISBNSearch::SearchISBN(std::vector<Content*> catalogue, long long ISBN)
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
