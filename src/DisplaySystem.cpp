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
	for (auto &pair : catalogue)
	{
		std::cout << pair.second->Display() << std::endl;
	}
}

void DisplaySystem::DisplayBooks(std::vector<Content*> catalogue)
{
	for(Content* c : catalogue)
	{
                std::cout << c.Display() << std::endl;
	}
}

void DisplaySystem::DisplayBooks(std::vector<CheckOutData*> checkOut)
{
	for(CheckOutData* c : checkOut)
	{
		std::cout << (c.contentCheckedOut).Display() << std::endl;
	}
}
void DisplaySystem::DisplayBooks(char choice, std::string genre, std::unordered_map<long long, Content*> catalogue)
{
	//Choice taken from main via user input from a menu of choices
	std::vector<Content*> temp;
	//Case for GenreSearch
	switch(choice) {
	case '1':
		searchAlgorithm = new GenreSearch();
        	temp = searchAlgorithm->SearchBooks(catalogue, genre);
        	this->DisplayBooks(temp);
		break;
	case '2':
		searchAlgorithm = new KeyWordSearch();
		temp = searchAlgorithm->SearchBooks(catalogue, genre);
		this->DisplayBooks(temp);
		break;
	}
}
void DisplaySystem::DisplayBooks(char choice, int ISBN, std::unordered_map<long long, Content*> catalogue)
{
	std::vector<Content*> temp;
	searchAlgorithm = new ISBNSearch();
	temp = searchAlgorithm->ISBNSearch(catalogue, ISBN);
	this->DisplayBooks(temp);
}
void DisplaySystem::DisplayBooks(char choice, std::unordered_map<long long, Content*> catalogue)
{
	std::vector<Content*> temp;
	switch(choice) {
	case '4':
		sortAlgorithm = new AlphabeticalSort();
		temp = sortAlgorithm->SortBooks(catalogue);
		this->DisplayBooks(temp);
		break;
	case '5':
		sortAlgorithm = new FrequencySort();
		temp = sortAlgorithm->SortBooks(catalogue);
		this->DisplayBooks(temp);
		break;
	}
}
void DisplaySystem::DisplayBooks(char choice, std::string genre, std::vector<CheckOutData*> usercat)
{
	std::vector<Content*> temp;
	switch(choice) {
        case '1':
                searchAlgorithm = new GenreSearch();
                temp = searchAlgorithm->SearchBooks(usercat, genre);
                this->DisplayBooks(temp);
                break;
        case '2':
                searchAlgorithm = new KeyWordSearch();
                temp = searchAlgorithm->SearchBooks(usercat, genre);
                this->DisplayBooks(temp);
                break;
        }
}

void DisplaySystem::DisplayBooks(char choice, int ISBN, std::vector<CheckOutData*> usercat)
{
        std::vector<Content*> temp;
        searchAlgorithm = new ISBNSearch();
        temp = searchAlgorithm->ISBNSearch(usercat, ISBN);
        this->DisplayBooks(temp);
}
void DisplaySystem::DisplayBooks(char choice, std::vector<CheckOutData*> usercat)
{
        std::vector<Content*> temp;
        switch(choice) {
        case '4':
                sortAlgorithm = new AlphabeticalSort();
                temp = sortAlgorithm->SortBooks(usercat);
                this->DisplayBooks(temp);
                break;
        case '5':
                sortAlgorithm = new FrequencySort();
                temp = sortAlgorithm->SortBooks(usercat);
                this->DisplayBooks(temp);
                break;
        }
}
