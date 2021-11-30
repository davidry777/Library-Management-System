#pragma once
 
#include <iostream>
#include <unordered_map>
#include <string>
#include "../header/Person.hpp"
#include "../header/User.hpp"
#include "../header/BookSystem.hpp"
#include "../header/Librarian.hpp"

using namespace std;

class UserSystem {
	private:
		unordered_map<int, Person*> people;
	public:
		UserSystem(string peopleInput, string checkedOut, vector<CheckOutData*>& checkedOut, deque<CheckOutData*>& passedDue);
		unordered_map<int, Person*>& GetMap()
		{
			return &this->people;
		}
		Person* GetPerson(int ID);
		void AddPerson(Person *newPeep);
		void SaveUserData(string userInfo);
//Person* GetCurrPeron(Person* dude, string password);	
			
}
