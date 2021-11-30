#ifndef __FREQUENCYSORT_H
#define __FREQUENCYSORT_H
#include "BookSort.hpp"

class FrequencySort : public BookSort {
 private:

 public:
        std::vector<Content*> SortBooks(std::unordered_map<long long, Content*>);
        std::vector<Content*> SortBooks(std::vector<CheckOutData*>);
        static bool compareFreq(Content*, Content*);
};
#endif
