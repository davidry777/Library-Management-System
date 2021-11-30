#pragma once

#include <iostream>
#include <unordered_map>
#include <deque>
#include <ctime>
#include <iomanip>
#include <fstream>

#include "json.hpp"

#include "Content.hpp"
#include "Book.hpp"
#include "Bundle.hpp"
#include "Person.hpp"

#include "CheckOutData.hpp"

class UserSystem;
class CheckOutData;

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

        void LoadCatalogue();
        void LoadCheckedOut(std::unordered_map<int, Person *>);
        void LoadPassedDue(std::unordered_map<int, Person *>);
        
        void SaveCatalogue(std::string file = "null");
        void SaveCheckedOut(std::string file = "null");
        void SavePassedDue(std::string file = "null");

        Content* GetContent(long long ISBN);
        std::vector<CheckOutData*>& GetPassedDue();
        std::deque<CheckOutData*>& GetCheckedOut();
        std::unordered_map<long long, Content*>& GetCatalogue();

        bool AddContent(Content* content);
        bool RemoveContent(long long ISBN);
        bool MakeBundle(const std::string& title, long long ISBN, const std::string& genre, const std::vector<long long> ISBNLists, int frequency = 0);

        CheckOutData* CheckOut(Person* person, long long ISBN);
        bool ReturnContent(Person* person, long long ISBN);
        void CheckExpiration();
};
