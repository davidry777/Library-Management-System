#pragma once

#include <iostream>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <string>

#include "LibrarySystem.hpp"

using namespace std;

class LoginSystem {
	private:
		unordered_map<int, string> userPasswords;
		UserSystem* userSystem;
	public:
		LoginSystem(unordered_map<int,string> userPasswords, UserSystem *userSystem);
		bool LoginVerify(int userID, string &userPass, unordered_map<int,Person*> &people);
		int HashPassword(string &userPass);
		void LogOut();
}
