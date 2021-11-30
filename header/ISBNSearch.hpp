#ifndef __ISBNSEARCH_H
#define __ISBNSEARCH_H
#include "BookSearch.hpp"

class ISBNSearch : public BookSearch {
 private:

 public:
        std::vector<Content*> SearchBooks(std::unordered_map<long long, Content*>, long long);
        std::vector<Content*> SearchBooks(std::vector<CheckOutData*>, long long);
        std::vector<Content*> SearchISBN(std::vector<Content*>, long long);
}
#endif
