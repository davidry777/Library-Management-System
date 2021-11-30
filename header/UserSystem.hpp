#pragma once
#ifndef __USERSYSTEM_HPP__
#define __USERSYSTEM_HPP__
 
#include <unordered_map>
#include <string>
<<<<<<< HEAD
#include "../header/Person.hpp"
#include "../header/User.hpp"
#include "../header/BookSystem.hpp"
#include "../header/Librarian.hpp"
=======
#include "Person.hpp"
#include "User.hpp"
#include "BookSystem.hpp"
#include "Librarian.hpp"
>>>>>>> 327bc230709b56475353b9a8b01818d43901434b
using namespace std;


class UserSystem {
	private:
		std::unordered_map<int, Person*> people;
	public:
		UserSystem(std::string peopleInput, std::string checkOut, std::vector<CheckOutData*>& checkedOut, std::deque<CheckOutData*>& passedDue, BookSystem* bs);
		~UserSystem();
		std::unordered_map<int, Person*>& GetMap();
		Person* GetPerson(int ID);
		void AddPerson(Person *person);
		void SaveUserData(std::string userInfo);
};

#endif
