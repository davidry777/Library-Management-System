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
#include "User.hpp"

#include <vector>
#include "CheckOutData.hpp"

class UserSystem;
class CheckOutData;

class BookSystem {
    private:
        std::unordered_map<long long, Content*> catalogue;
        std::unordered_map<int, std::vector<CheckOutData*>> checkedOut;

        std::string catalogueFile; 
        std::string checkedOutFile;

        int maximumSeconds;

        void DeallocateContent(Content* content);
        bool FindInCheckedOutVec(std::vector<CheckOutData*>& userVec, long long ISBN);
    public:
        BookSystem() = default;
        BookSystem(const std::string& catF, const std::string& coF, int maxSec = 259200);
        ~BookSystem();

        bool AddContent(Content* content);
        bool MakeBundle(const std::string& title, long long ISBN, const std::string& genre, const std::vector<Content*>& contents);
        bool RemoveContent(long long ISBN);

        bool CheckOut(Person* person, long long ISBN);
        bool ReturnContent(Person* person, long long ISBN);
        void CheckExpiration();

        std::unordered_map<long long, Content*>& GetCatalogue();
        std::unordered_map<int, std::vector<CheckOutData*>>& GetCheckedOut();
        Content* GetContent(long long ISBN);

        void LoadCatalogue();
        void SaveCatalogue(std::string file = "null");

        void LoadCheckedOut(std::unordered_map<int, Person *>);
        void SaveCheckedOut(std::string file = "null");
};

#endif //__BOOKSYSTEM_HPP__
