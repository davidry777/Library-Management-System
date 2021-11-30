#pragma once

#include <unordered_map>
#include <fstream>
#include <string>

class LoginSystem {
	private:
		unordered_map<int, int> userPasswords; //<userID, hashed password>
	public:
		LoginSystem(std::string textFile);
		bool LoginVerify(int userID, std::string &userPass);
		int HashPassword(std::string &userPass);
		void SaveUsers(std::string textFile);
		int GetHashPass(int ID);
};
