#include "../header/DisplaySystem.h"
#include "GenreSearch.cpp"
#include "SubgenreSearch.cpp"
#include "ISBNSearch.cpp"
#include "AlphabeticalSort.cpp"
#include "FrequencySort.cpp"

DisplaySystem::DisplaySystem() 
{ 
	searchAlgorithm = nullptr;
	sortAlgorithm = nullptr;
}

DisplaySystem::~DisplaySystem()
{
	delete searchAlgorithm;
	delete sortAlgorithm;
}

void DisplaySystem::DisplayBooks(std::unordered_map<long long, Content*> catalogue)
{
	//I need to rewrite this
	for(Content* c: catalogue)
	{
		std::cout << c.Display() << std::endl;
	}
}

void DisplaySystem::DisplayBooks(std::vector<CheckedOut*> checkOut)
{
	for(CheckedOut c : checkOut)
	{
		std::cout << c.Display() << std::endl;
	}
}
void DisplaySystem::DisplayBooks(char choice, std::string genre, std::unordered_map<long long, Content*> catalogue)
{
	//Choice taken from main via user input from a menu of choices
	std::vector<Book*> temp;
	switch(choice) {
	//Case for GenreSearch
	case '1':
		searchAlgorithm = new GenreSearch();
		temp = searchAlgorithm->SearchBooks(catalogue, genre);
		this->DisplayBooks(temp);
		break;
	//Case for SubgenreSearch
}
void DisplaySystem::DisplayBooks(char choice, int ISBN, std::unordered_map<long long, Content*> catalogue)
{
	std::vector<Book*> temp;
	searchAlgorithm = new ISBNSearch();
	temp = searchAlgorithm->ISBNSearch(catalogue, ISBN);
	this->DisplayBooks(temp);
}
void DisplaySystem::DisplayBooks(char choice, std::unordered_map<long long, Content*> catalogue)
{
	std::vector<Book*> temp;
	switch(choice) {
	case '3':
		sortAlgorithm = new AlphabeticalSort();
		temp = sortAlgorithm->SortBooks(catalogue);
		this->DisplayBooks(temp);
		break;
	case '4':
		sortAlgorithm = new FrequencySort();
		temp = sortAlgorithm->SortBooks(catalogue);
		this->DisplayBooks(temp);
		break;
	}
}

