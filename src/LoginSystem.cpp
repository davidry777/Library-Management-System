#include "../header/LoginSystem.hpp"
#include <fstream>

using namespace std;

LoginSystem::LoginSystem(unordered_map<int, int> *userPasses, UserSystem *uSystem) : UserSystem(uSystem) 
{		
	//TODO: populate userPasses from text file
	ifstream file;
	file.open("users.txt");
	int temp, tempPass, tempUserID;
	if (file.isopen())
	{
		while (!file.eof())
		{
			file >> tempUserID >> tempPass;		
			userPasses.insert({tempUserID, tempPass});
		}
	}
	this->userPasswords = userPasses;
	//temporary stub
	//userPasses[1] = a*1984+2049;
}

LoginSystem::~LoginSystem()
{
	//saving these to a file will be done in the log out function
	for (auto x : userPasswords)
		delete x;
}

int LoginSystem::HashPassword(string &userPass) 
{
	int hash = -1; //if no password is given, returns -1
	for (auto c : userPass.toCharArray())
		hash += int(c)*1984 + 2049;
	return hash;
		
}

bool LoginSystem::LoginVerify(int userID, string &userPass, unordered_map<int, Person*> &people)
{
	bool allowLogin = false;
	int hash = HashPassword(userPass);
	if (people[userID] == hash)
		allowLogin = true;
	return allowLogin;
}

void LoginSystem::SaveUsers()
{
	ofstream fileOut;
	fileOut.open("users.txt");
	if (fileOut.isopen())
		for (const auto & [ID,pass] : userPasses)
		{
			fileOut << ID << " " << pass << endl;	
		}
	//TOOD: LogOut
	//save users to file
	//deconstruct?
	//do log out stuff
}

int LoginSystem::GetHashPass(int ID)
{
	return this->userPasses[ID];
}
