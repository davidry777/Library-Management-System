#pragma once
#ifndef __USERSYSTEM_HPP__
#define __USERSYSTEM_HPP__
 
#include <unordered_map>
#include <string>
#include "../header/Person.hpp"
#include "../header/User.hpp"
#include "../header/BookSystem.hpp"
#include "../header/Librarian.hpp"
using namespace std;


class UserSystem {
	private:
		std::unordered_map<int, Person*> people;
	public:
		UserSystem(std::string peopleInput, std::string checkOut, std::vector<CheckOutData*>& checkedOut, std::deque<CheckOutData*>& passedDue);
		std::unordered_map<int, Person*>& GetMap();
		Person* GetPerson(int ID);
		void AddPerson(Person *person);
		void SaveUserData(std::string userInfo);
};

#endif
