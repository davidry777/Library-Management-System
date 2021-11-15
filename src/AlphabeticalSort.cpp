#include "../header/BookSort.h"

class AlphabeticalSort : public BookSort
{
	private:

	public:
		std::vector<Book*>& SortBooks(std::vector<Book*> &catalogue)
		{
			//This uses the standard library sorting function to sort books alphabetically by title
			std::sort(catalogue.begin(), catalogue.end(), this->compareStr);
			return catalogue;
		}
		static bool compareStr(Book* a, Book* b)
		{
			if(a->getTitle().compare(b->getTitle()) < 0)
			{
				return true;
			}
			else
				if(a->getTitle().compare(b->getTitle()) > 0)
				{
					return false;
				}
				else
					return false;
		}
};
