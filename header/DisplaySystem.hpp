#ifndef __DISPLAYSYSTEM_HPP__
#define __DISPLAYSYSTEM_HPP__

#include "BookSort.hpp"
#include "BookSearch.hpp"
#include "BookSystem.hpp"
#include <iostream>

class DisplaySystem {
private:
	//Stores pointers to the search and sort algorithms
	BookSearch* searchAlgorithm;
	BookSort* sortAlgorithm;

public:
	DisplaySystem();
	~DisplaySystem();
	void DisplayBooks(std::vector<Book*>);
	void DisplayBooks(std::vector<CheckedOutData*>)
	void DisplayBooks(char, std::string, std::vector<Book*>);
	void DisplayBooks(char, int, std::vector<Book*>);
	void DisplayBooks(char, std::vector<Book*>);
};

#endif	//__DISPLAYSYSTEM_HPP__
