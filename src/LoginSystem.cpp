#include "../header/LoginSystem.hpp"

using namespace std;

LoginSystem::LoginSystem(unordered_map<int, Person*> userList)
{
	for (pair<int, Person*> x : userList)
  {
    userPasswords[x.first] = x.second->GetHashedPassword();
  } 
}

void LoginSystem::AddPass(int ID, int userPass)
{
  userPasswords[ID] = userPass;
}

int LoginSystem::HashPassword(string userPass) 
{
	int hash = 0; //if no password is given, returns 0
	for (int i = 0; i < userPass.length(); ++i)
		hash += (i+1)*(int)userPass[i]*1984 + 2049;
	return hash;
}

bool LoginSystem::LoginVerify(int userID, string userPass)
{
	bool allowLogin = false;
	int hash = HashPassword(userPass);
	if (userPasswords[userID] == hash)
		allowLogin = true;
	return allowLogin;
}

int LoginSystem::GetHashPass(int ID)
{
	return this->userPasswords[ID];
}
