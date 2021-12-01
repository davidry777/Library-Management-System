#pragma once
#ifndef __BOOKSYSTEM_HPP__
#define __BOOKSYSTEM_HPP__

#include <iostream>
#include <unordered_map>
#include <ctime>
#include <iomanip>
#include <fstream>

#include "json.hpp"

#include "Content.hpp"
#include "Book.hpp"
#include "Bundle.hpp"
#include "Person.hpp"

#include <vector>
#include <set>
#include "CheckOutData.hpp"

class UserSystem;
class CheckOutData;

class BookSystem {
    private:
        std::unordered_map<long long, Content*> catalogue;
        std::unordered_map<int, std::set<CheckOutData*>> checkedOut;

        std::string catalogueFile; 
        std::string checkedOutFile;

        int maximumSeconds;
    public:
        BookSystem(const std::string& catF, const std::string& coF, int maxSec = 259200);
        ~BookSystem();

        void LoadCatalogue();
        void SaveCatalogue(std::string file = "null");
        std::unordered_map<long long, Content*>& GetCatalogue();

        void LoadCheckedOut(std::unordered_map<int, Person *>);
        void SaveCheckedOut(std::string file = "null");
        unordered_map<int, std::set<CheckOutData*>>& GetCheckedOut();


        Content* GetContent(long long ISBN);
        bool AddContent(Content* content);
        bool RemoveContent(long long ISBN);
        bool MakeBundle(const std::string& title, long long ISBN, const std::string& genre, const std::vector<Content*>& contents);

        CheckOutData* CheckOut(Person* person, long long ISBN);
        bool ReturnContent(Person* person, long long ISBN);
        void CheckExpiration();
};

#endif //__BOOKSYSTEM_HPP__
