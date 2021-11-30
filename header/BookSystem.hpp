#pragma once

#include <iostream>
#include <unordered_map>
#include <deque>
#include <ctime>

#include <fstream>
#include "json.hpp"

#include "Person.hpp"
#include "Content.hpp"
#include "Book.hpp"
#include "Bundle.hpp"

struct CheckOutData {
    time_t timeCheckedOut;
    Content* contentCheckedOut;
    Person* userCheckedOut;
    bool overTime;

    CheckOutData(time_t a, Content* b, Person* c, bool overTime = false) : timeCheckedOut(a), contentCheckedOut(b), userCheckedOut(c), overTime(false) {}
    int SecondsPassed() { return time(0) - timeCheckedOut; }
};

class BookSystem {
    private:
        std::unordered_map<long long, Content*> catalogue;
        std::vector<CheckOutData*> passedDue;
        std::deque<CheckOutData*> checkedOut;

        std::string catalogueFile; 
        std::string checkedOutFile; 
        std::string passedDueFile; 
    public:
        BookSystem(const std::string& catalogueFile, const std::string& checkedOutFile, const std::string& passedDueFile);
        ~BookSystem();
        Content* GetContent(long long ISBN);

        bool AddContent(Content* content);
        bool RemoveContent(long long ISBN);
        bool MakeBundle(const std::string& title, long long ISBN, const std::string& genre, const std::vector<long long> ISBNLists, int frequency = 0);

        CheckOutData* CheckOut(Person* person, long long ISBN);
        bool ReturnContent(Person* person, long long ISBN);
        void CheckExpiration();
};
