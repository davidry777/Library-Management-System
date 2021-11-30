#include "../header/DisplaySystem.hpp"
#include "../header/AlphabeticalSort.hpp"
#include "../header/FrequencySort.hpp"
#include "../header/GenreSearch.hpp"
#include "../header/ISBNSearch.hpp"
#include "../header/KeyWordSearch.hpp"

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
        std::cout << c->Display() << std::endl;
	}
}

void DisplaySystem::DisplayBooks(std::vector<CheckOutData*> checkOut)
{
	for(CheckOutData* c : checkOut)
	{
		std::cout << (c->contentCheckedOut)->Display() << std::endl;
	}
}
void DisplaySystem::DisplayBooks(char choice, std::string genre, std::unordered_map<long long, Content*> catalogue)
{
	//Choice taken from main via user input from a menu of choices
	std::vector<Content*> temp;
	//Case for GenreSearch
	switch(choice) {
	case '1':
	{
		GenreSearch* g = new GenreSearch();
        	temp = g->SearchBooks(catalogue, genre);
        	this->DisplayBooks(temp);
		break;
	}
	case '2':
	{
		KeyWordSearch* k = new KeyWordSearch();
		temp = k->SearchBooks(catalogue, genre);
		this->DisplayBooks(temp);
		break;
	}
	}
}
void DisplaySystem::DisplayBooks(char choice, int ISBN, std::unordered_map<long long, Content*> catalogue)
{
	std::vector<Content*> temp;
	ISBNSearch* i = new ISBNSearch();
	temp = i->SearchBooks(catalogue, ISBN);
	this->DisplayBooks(temp);
}
void DisplaySystem::DisplayBooks(char choice, std::unordered_map<long long, Content*> catalogue)
{
	std::vector<Content*> temp;
	switch(choice) {
	case '4':
	{
		AlphabeticalSort* a = new AlphabeticalSort();
		temp = a->SortBooks(catalogue);
		this->DisplayBooks(temp);
		break;
	}
	case '5':
	{
		FrequencySort* f = new FrequencySort();
		temp = f->SortBooks(catalogue);
		this->DisplayBooks(temp);
		break;
	}
	}
}
void DisplaySystem::DisplayBooks(char choice, std::string genre, std::vector<CheckOutData*> usercat)
{
	std::vector<Content*> temp;
	switch(choice) {
        case '1':
 	{
	        GenreSearch* g = new GenreSearch();
                temp = g->SearchBooks(usercat, genre);
                this->DisplayBooks(temp);
                break;
        }
	case '2':
        {
	        KeyWordSearch* k = new KeyWordSearch();
                temp = k->SearchBooks(usercat, genre);
                this->DisplayBooks(temp);
                break;
        }
	}
}

void DisplaySystem::DisplayBooks(char choice, int ISBN, std::vector<CheckOutData*> usercat)
{
        std::vector<Content*> temp;
        ISBNSearch* i = new ISBNSearch();
        temp = i->SearchBooks(usercat, ISBN);
        this->DisplayBooks(temp);
}
void DisplaySystem::DisplayBooks(char choice, std::vector<CheckOutData*> usercat)
{
        std::vector<Content*> temp;
        switch(choice) {
        case '4':
        {
	        AlphabeticalSort* a = new AlphabeticalSort();
                temp = a->SortBooks(usercat);
                this->DisplayBooks(temp);
                break;
        }
	case '5':
        {
	        FrequencySort* f = new FrequencySort();
                temp = f->SortBooks(usercat);
                this->DisplayBooks(temp);
                break;
        }
	}
}
