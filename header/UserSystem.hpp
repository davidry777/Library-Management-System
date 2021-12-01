#pragma once
#ifndef __USERSYSTEM_HPP__
#define __USERSYSTEM_HPP__
 
#include <unordered_map>
#include <string>
#include "Person.hpp"
#include "User.hpp"
#include "BookSystem.hpp"
#include "Librarian.hpp"
using namespace std;


class UserSystem {
	private:
		std::unordered_map<int, Person*> people;
	public:
		UserSystem(string peopleInput, string checkOut, unordered_map<int, set<CheckOutData*>> checkedOut, BookSystem* bs);
		~UserSystem();
		std::unordered_map<int, Person*>& GetMap();
		Person* GetPerson(int ID);
		void AddPerson(Person *person);
		void SaveUserData(std::string userInfo);
};

#endif
