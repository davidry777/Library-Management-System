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
	DisplaySystem();
	~DisplaySystem();
	void DisplayBooks(std::unordered_map<int, Content*>);
	void DisplayBooks(std::vector<CheckedOut*>)
	void DisplayBooks(char, std::string, std::unordered_map<int, Content*>>);
	void DisplayBooks(char, int, std::unordered_map<int, Content*>>);
	void DisplayBooks(char, std::unordered_map<int, Content*>>);
};
#endif
