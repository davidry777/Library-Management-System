#pragma once

#include <unordered_map>
#include <string>

#include "UserSystem.hpp"

using namespace std;

class LoginSystem {
	private:
		unordered_map<int, int> userPasswords; //<userID, hashed password>
		UserSystem* userSystem;
	public:
		LoginSystem(unordered_map<int,int> userPasswords, UserSystem *userSystem);
		bool LoginVerify(int userID, string &userPass, unordered_map<int,Person*> &people);
		int HashPassword(string &userPass);
		void LogOut();
}
