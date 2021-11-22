#ifndef __DISPLAYSSYTEM_H
#define __DISPLAYSSYSTEM_H
#include "BookSort.hpp"
#include "BookSearch.hpp"
#include <iostream>

class DisplaySystem {
private:
	//Stores pointers to the search and sort algorithms
	BookSearch* searchAlgorithm;
	BookSort* sortAlgorithm;

public:
	void DisplayBooks(std::vector<Book*>);
	void DisplayBooks(std::vector<CheckedOut*>)
};
#endif
