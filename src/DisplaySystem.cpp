#include "DisplaySystem.h"

DisplaySystem::DisplaySystem() { }

void DisplaySystem::DisplayBooks(std::vector<Book*> catalogue)
{
	for(Book b : catalogue)
	{
		b.Display();
		std::cout << endl;
	}
}

void DisplaySystem::DisplayBooks(std::vector<CheckedOut*> checkOut)
{
	for(CheckedOut c : checkOut)
	{
		c.Display();
		std::cout << endl;
	}
}
void DisplaySystem::DisplayBooks(char choice, std::vector<Book*> catalogue)
{
	//Choice taken from main via user input from a menu of choices
	std::vector<Book*> temp;
	std::string genre;
	int ISBN;
	switch(choice {
	//Case for GenreSearch
	case '1':
		searchAlgorithm = new GenreSearch();
		temp = searchAlgorithm->SearchBooks(catalogue);
		this->DisplayBooks(temp);
		break;
	//Case for SubgenreSearch
	case '2':
		searchAlgorithm = new SubgenreSearch();
		temp = searchAlgorith->SearchBooks(catalogue);
		this->DisplayBooks(temp);
		break;
	//Case for ISBNSearch
	case '3':
		searchAlgorithm = new ISBNSearch();
		ISBN = 
		temp = searchAlgorithm->SearchBooks(catalogue, ISBN);
		this->DisplayBooks(temp);
		break;
	//Case for AlphabeticalSort
	case '4':
		sortAlgorithm = new AlphabeticalSort();
		temp = sortAlgorithm->SortBooks(catalogue);
		this->DisplayBooks(temp);
		break;
	}
}
