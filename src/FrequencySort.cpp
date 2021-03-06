#include "../header/FrequencySort.hpp"

std::vector<Content*> FrequencySort::SortBooks(std::unordered_map<long long, Content*> catalogue)
{
	//Everything in here needs a rework
	//This uses the standard library sorting function to sort books alphabetically
	std::vector<Content*> mapped = MapToVector(catalogue);
	std::sort(mapped.begin(), mapped.end(), this->compareFreq);
	return mapped;
}
std::vector<Content*> FrequencySort::SortBooks(std::vector<CheckOutData*> usercat)
{
	std::vector<Content*> mapped = MapToVector(usercat);
	std::sort(mapped.begin(), mapped.end(), this->compareFreq);
	return mapped;
}
bool FrequencySort::compareFreq(Content* a, Content* b)
{
	return a->GetFrequency() > b->GetFrequency();
}
