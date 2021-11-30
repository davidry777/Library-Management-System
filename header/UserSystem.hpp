#pragma once
 
#include <unordered_map>
#include <string>
#include <fstream>
#include "Librarian.hpp"
#include "User.hpp"
#include "LibrarySystem.hpp"
#include "CheckOutData.hpp"
#include "json.hpp"
#include "Person.hpp"

using namespace std;

class LibrarySystem;

class UserSystem {
	private:
		unordered_map<int, Person*> people;
	public:
		UserSystem(string peopleInput, string checkOut, vector<CheckOutData*>& checkedOut, deque<CheckOutData*>& passedDue, LibrarySystem* set_library);
		unordered_map<int, Person*>& GetMap();
		Person* GetPerson(int ID);
		void AddPerson(Person *person);
		void SaveUserData(string userInfo);
};