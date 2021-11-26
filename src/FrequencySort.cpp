#include "../header/BookSort.hpp"

class FrequencySort : public BookSort
{
	private:
	
	public:
		std::vector<Book*>& SortBooks(std::vector<Book*> catalogue)
		{
			//This uses the standard library sorting function to sort books alphabetically
			std::sort(catalogue.begin(), catalogue.end(), this->compareFreq);
			return catalogue;
		}
		static bool compareFreq(Book* a, Book* b)
		{
			return a->GetFrequency() > b->GetFrequency();
		}
}
