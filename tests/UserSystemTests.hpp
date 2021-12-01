#pragma once
#include "../header/UserSystem.hpp"
#include <fstream>
#include "../header/LoginSystem.hpp"
#include "gtest/gtest.h"
// #include "../header/Person.hpp"

using namespace std;
using json = nlohmann::json;

// TEST(UserSystemTest, Deconstruct) {
//   		UserSystem(string peopleInput, string checkOut, vector<CheckOutData*>& checkedOut, deque<CheckOutData*>& passedDue, LibrarySystem* set_library);
//   string peopleInput = "test_users.json";
//   string checkOut = "checkOut.txt";
//   vector<CheckOutData*> checkedOut; deque<CheckOutData*> passedDue;
//   UserSystem *userSys = new UserSystem(peopleInput,checkOut,checkedOut,passedDue, nullptr);
//   delete userSys;
//   ifstream fileUse(peopleInput);
//   EXPECT_EQ(false, is_empty(fileUse));
// }

TEST(UserSystemTest, GetMap) {
  string peopleInput = "../tests/test_files/test_users.json";
  string checkOut = "checkOut.txt";
  vector<CheckOutData*> checkedOut; deque<CheckOutData*> passedDue;
  UserSystem *userSys = new UserSystem(peopleInput,checkOut,checkedOut,passedDue, nullptr);
  unordered_map<int, Person*> peopleTest = userSys->GetMap();
  EXPECT_EQ(peopleTest[18658864]->GetId(), 11464202); //passwords of test data set
  delete userSys;
}

TEST(UserSystemTest, GetAPerson) {
  string peopleInput = "../tests/test_files/test_users.json";
  string checkOut = "checkOut.txt";
  vector<CheckOutData*> checkedOut; deque<CheckOutData*> passedDue;
  UserSystem *userSys = new UserSystem(peopleInput,checkOut,checkedOut,passedDue, nullptr);
  EXPECT_NE(userSys->GetPerson(18679479), nullptr);
}

TEST(UserSystemTest, GetAFakePerson) {
  string peopleInput = "../tests/test_files/test_users.json";
  string checkOut = "checkOut.txt";
  vector<CheckOutData*> checkedOut; deque<CheckOutData*> passedDue;
  UserSystem *userSys = new UserSystem(peopleInput,checkOut,checkedOut,passedDue, nullptr);
  EXPECT_EQ(userSys->GetPerson(7), nullptr);
}

TEST(UserSystemTest, AddAPerson) {
  string peopleInput = "../tests/test_files/test_users.json";
  string checkOut = "checkOut.txt";
  int hash = 39052307;
  vector<CheckOutData*> checkedOut; deque<CheckOutData*> passedDue;
  UserSystem *userSys = new UserSystem(peopleInput,checkOut,checkedOut,passedDue, nullptr);
  User* testPerson = new User("steve", 18628694, nullptr, hash);//password is Lskdjf;lksjdgkjdsdg
  userSys->AddPerson(testPerson);
  EXPECT_EQ(userSys->GetPerson(18628694)->GetId(), 18628694);
}

TEST(UserSystemTest, SaveUserData) {
  string peopleInput = "../tests/test_files/test_users.json";
  string checkOut = "checkOut.txt";
  vector<CheckOutData*> checkedOut; deque<CheckOutData*> passedDue;
  UserSystem *userSys = new UserSystem(peopleInput,checkOut,checkedOut,passedDue, nullptr);
  EXPECT_EQ(userSys->GetPerson(18658864)->GetId(),18658864);
}