#pragma once
#ifndef __USERSYSTEM_HPP__
#define __USERSYSTEM_HPP__
 
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <deque>

#include "Person.hpp"
#include "User.hpp"
#include "Librarian.hpp"
#include "LibrarySystem.hpp"
#include "CheckOutData.hpp"
#include "json.hpp"

class LibrarySystem;

class UserSystem {
	private:
		std::unordered_map<int, Person*> people;
	public:
		UserSystem(std::string peopleInput, std::string checkOut, std::vector<CheckOutData*>& checkedOut, std::deque<CheckOutData*>& passedDue, LibrarySystem* set_library);
		std::unordered_map<int, Person*>& GetMap();
		Person* GetPerson(int ID);
		void AddPerson(Person *person);
		void SaveUserData(std::string userInfo);
};

#endif
