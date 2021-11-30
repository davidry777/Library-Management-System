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
		LoginSystem();
		bool LoginVerify(int userID, std::string &userPass, unordered_map<int,Person*> &people);
		int HashPassword(std::string &userPass);
		void SaveUsers();
		int GetHashPass(int ID);
};
