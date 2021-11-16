#include "../header/LoginSystem.hpp"

using namespace std;

LoginSystem::LoginSystem(unordered_map<int, string> *userPasses, UserSystem *uSystem) : UserSystem(uSystem) 
{
	
	//populate userPasses from text file
}

LoginSystem::~LoginSystem()
{
	//saving these to a file will be done in the log out function
	for (auto x : userPasswords)
		delete x;
}

int HashPassword(string &userPass) 
{
	int hash = -1; //if no password is given, returns -1
	for (auto c : userPass.toCharArray())
		hash += int(c)*1984 + 2049;
	return hash;
		
}

bool LoginVerify(int userID, string &userPass, unordered_map<int, Person*> &people)
{
	bool allowLogin = false;
	int hash = HashPassword(userPass);
	if (people[userID] == hash)
		allowLogin = true;
	return allowLogin;
}

void LogOut()
{
	//save users to file
	//deconstruct?
	//do log out stuff
}
