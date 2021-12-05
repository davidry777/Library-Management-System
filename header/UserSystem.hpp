#pragma once
#ifndef __USERSYSTEM_HPP__
#define __USERSYSTEM_HPP__

#include <unordered_map>
#include <string>
#include "Person.hpp"
#include "User.hpp"
#include "BookSystem.hpp"
#include "Librarian.hpp"
#include "LoginSystem.hpp"
using namespace std;


class UserSystem {
	private:
		std::unordered_map<int, Person*> people;
	public:
		UserSystem() = default;
		UserSystem(string peopleInput, BookSystem* bs);
		~UserSystem();
		std::unordered_map<int, Person*>& GetMap();
		Person* GetPerson(int ID);
    void AddPerson(LoginSystem *logSys, Person *person);
		void SaveUserData(std::string userInfo);
    void AddCheckedOut(const unordered_map<int, vector<CheckOutData>>& checkedOut);
};

#endif
