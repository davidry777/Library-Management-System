#include "../header/AlphabeticalSort.hpp"

std::vector<Content*> AlphabeticalSort::SortBooks(std::unordered_map<long long, Content*> catalogue)
{
	//This uses the standard library sorting function to sort books alphabetically by title
	std::vector<Content*> mapped = MapToVector(catalogue);
	std::sort(mapped.begin(), mapped.end(), this->compareStr);
	return mapped;
}
std::vector<Content*> AlphabeticalSort::SortBooks(std::vector<CheckOutData*> usercat)
{
	std::vector<Content*> mapped = MapToVector(usercat);
	std::sort(mapped.begin(), mapped.end(), this->compareStr);
	return mapped;
}
bool AlphabeticalSort::compareStr(Content* a, Content* b)
{
	if(a->GetTitle().compare(b->GetTitle()) < 0)
	{
		return true;
	}
	else
		if(a->GetTitle().compare(b->GetTitle()) > 0)
		{
			return false;
		}
		else
			return false;
}
