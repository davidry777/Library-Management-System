#include "../header/AlphabeticalSort.h"

class AlphabeticalSort : public BookSort
{
	private:

	public:
		std::vector<Content*> SortBooks(std::unordered_map<long long, Content*> catalogue)
		{
			//This uses the standard library sorting function to sort books alphabetically by title
			vector<Content*> mapped = MapToVector(catalogue)
			std::sort(mapped.begin(), mapped.end(), this->compareStr);
			return mapped;
		}
		std::vector<Content*> SortBooks(std::vector<CheckOutData*> usercat)
		{
			std::vector<Content*> mapped = MapToVector(usercat);
			std::sort(mapped.begin(), mapped.end(), this->compareStr);
			return mapped;
		}
		static bool compareStr(Content* a, Content* b)
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
};
