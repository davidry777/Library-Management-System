#pragma once
 
#include <iostream>
#include <unordered_map>
#include <string>

#include "Person.hpp"

using namespace std;

class UserSystem {
	private:
		Person *currPerson;
		unordered_map<int, Person*> people;
	public:
		UserSystem(Person *cPerson, unordered_map<int, Person*> peeps;
		void AddPerson(Person *newPeep);
		Person* GetCurrPeron(Person* dude, string password);	
			
}
