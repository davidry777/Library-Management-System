#pragma once

#include <unordered_map>
#include <fstream>
#include <string>
#include "Person.hpp"

using namespace std;

class LoginSystem {
	private:
		unordered_map<int, int> userPasswords; //<userID, hashed password>
	public:
  
    LoginSystem(unordered_map<int, Person*> userList);
		bool LoginVerify(int userID, std::string userPass);
		int HashPassword(std::string userPass);
		// void SaveUsers(std::string textFile);
		int GetHashPass(int ID);
    void AddPass(int ID, int userPass);
};
