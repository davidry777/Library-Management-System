#ifndef __GENRESEARCH_H
#define __GENRESEARCH_H
#include "BookSearch.hpp"

class GenreSearch : public BookSearch {
 private:

 public:
	std::vector<Content*> SearchBooks(std::unordered_map<long long, Content*>, std::string);
	std::vector<Content*> SearchBooks(std::vector<CheckOutData*>, std::string);
	std::vector<Content*> SearchGenre(std::vector<Content*>, std::string);
};
#endif
