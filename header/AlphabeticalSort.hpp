#ifndef __ALPHABETICALSORT_H
#define __ALPHABETICALSORT_H
#include "BookSort.hpp"

class AlphabeticalSort : public BookSort {
 private:

 public:
	std::vector<Content*> SortBooks(std::unordered_map<long long, Content*>);
	std::vector<Content*> SortBooks(std::vector<CheckOutData*>);
	static bool compareStr(Content*, Content*);
};
#endif
