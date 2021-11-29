#include "../header/BookSort.h"

class FrequencySort : public BookSort
{
	private:
	
	public:
		std::vector<Content*> SortBooks(std::unordered_map<long long, Content*> catalogue)
		{
			//Everything in here needs a rework
			//This uses the standard library sorting function to sort books alphabetically
			std::vector<Content*> mapped = MapToVector(catalogue);
			std::sort(mapped.begin(), mapped.end(), this->compareFreq);
			return mapped;
		}
		static bool compareFreq(Content* a, Content* b)
		{
			return a->GetFrequency() > b->GetFrequency();
		}
}
