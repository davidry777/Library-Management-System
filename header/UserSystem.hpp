#pragma once
 
#include <iostream>
#include <unordered_map>
#include <string>

#include "Person.hpp"

using namespace std;

class UserSystem {
	private:
		unordered_map<int, Person*> people;
	public:
		UserSystem();
		Person* GetPerson(int ID);
		void AddPerson(Person *newPeep);
		Person* GetCurrPeron(Person* dude, string password);	
			
}
