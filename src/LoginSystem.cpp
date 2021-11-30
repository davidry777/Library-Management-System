#include "../header/LoginSystem.hpp"
#include <fstream>
#include <unordered_map>

using namespace std;

LoginSystem::LoginSystem(string textFile)//should be .txt
{		
	ifstream file;
	file.open(textFile);
	int temp, tempPass, tempUserID;
	unordered_map<int, int> userPasses;
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> tempUserID >> tempPass;		
			userPasses.insert({tempUserID, tempPass});
		}
	}
	this->userPasswords = userPasses;
}

LoginSystem::~LoginSystem()
{
	for (auto x : userPasswords)
		delete x;
}

int LoginSystem::HashPassword(string &userPass) 
{
	int hash = 0; //if no password is given, returns 0
	for (auto c : userPass)
		hash += int(c)*1984 + 2049;
	return hash;
}

bool LoginSystem::LoginVerify(int userID, string &userPass)
{
	bool allowLogin = false;
	int hash = HashPassword(userPass);
	if (userPasswords[userID] == hash)
		allowLogin = true;
	return allowLogin;
}

void LoginSystem::SaveUsers(string textFile)
{
	ofstream fileOut;
	fileOut.open(textFile);
	if (fileOut.is_open())
		for (const auto & [ID,pass] : userPasswords)
		{
			fileOut << ID << " " << pass << endl;	
		}
  fileOut.close();
}

int LoginSystem::GetHashPass(int ID)
{
	return this->userPasswords[ID];
}
