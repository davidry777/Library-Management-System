#include "../header/LoginSystem.hpp"

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

int LoginSystem::HashPassword(string &userPass) 
{
	int hash = 0; //if no password is given, returns 0
	for (int i = 0; i < userPass.length(); ++i)
		hash += (i+1)*(int)userPass[i]*1984 + 2049;
	return hash;
}

int HashPassword(string &userPass) 
{
	int hash = 0; //if no password is given, returns 0
	for (int i = 0; i < userPass.length(); ++i)
		hash += (i+1)*(int)userPass[i]*1984 + 2049;
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
		for (auto kv : userPasswords)
		{
			fileOut << kv.first << " " << kv.second << endl;	
		}
  fileOut.close();
}

int LoginSystem::GetHashPass(int ID)
{
	return this->userPasswords[ID];
}
