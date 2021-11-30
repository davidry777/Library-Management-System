#pragma once

#include <unordered_map>
#include <string>
#include "../header/Person.hpp"
#include "../header/User.hpp"
#include "../header/Librarian.hpp"
#include "UserSystem.hpp"
#include "../header/BookSystem.hpp"

class LoginSystem {
	private:
		unordered_map<int, int> userPasswords; //<userID, hashed password>
	public:
		LoginSystem(string textFile);
		bool LoginVerify(int userID, std::string &userPass);
		int HashPassword(std::string &userPass);
		void SaveUsers(string textFile);
		int GetHashPass(int ID);
};
