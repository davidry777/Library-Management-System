#pragma once

#include <unordered_map>
#include <string>

#include "UserSystem.hpp"

using namespace std;

class LoginSystem {
	private:
		unordered_map<int, int> userPasswords; //<userID, hashed password>
	public:
		LoginSystem();
		bool LoginVerify(int userID, string &userPass, unordered_map<int,Person*> &people);
		int HashPassword(string &userPass);
		void SaveUsers();
		int GetHashPass(int ID);
}
