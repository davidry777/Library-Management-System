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

void DisplaySystem::DisplaySystem(std::vector<CheckedOut*> checkOut)
{
	for(CheckedOut c : checkOut)
	{
		c.Display();
		std::cout << endl;
	}
}
