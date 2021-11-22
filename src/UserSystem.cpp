#include "../header/UserSystem.hpp"
#include "../header/Person.hpp"
#include "../header/LoginSystem.hpp"

UserSystem::UserSystem(unordered_map<int, Person*> users, Person *nowPerson)
{
	//import users from a file to populate the array
			
}

Person* UserSystem::SetCurrPerson(Person *dude, string password) {
	if (LoginVerify(dude->ID, password, users))
		return dude;
	else
		return nullptr;
}

void UserSystem::AddPerson(Person *dude) {
	this->users.insert({ dude->ID, dude });	
}
