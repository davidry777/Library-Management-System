#ifndef __KEYWORDSEARCH_H
#define __KEYWORDSEARCH_H
#include "BookSearch.hpp"

class KeyWordSearch : public BookSearch {
 private:

 public:
        std::vector<Content*> SearchBooks(std::unordered_map<long long, Content*>, std::string);
        std::vector<Content*> SearchBooks(std::vector<CheckOutData*>, std::string);
        std::vector<Content*> SearchKeyWord(std::vector<Content*>, std::string);
};
#endif
