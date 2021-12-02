#pragma once
#include "../header/UserSystem.hpp"
#include <fstream>
#include "../header/LoginSystem.hpp"
#include "gtest/gtest.h"
// #include "../header/Person.hpp"

using namespace std;
using json = nlohmann::json;

TEST(UserSystemTest, Construct)
{
  UserSystem *userSys = new UserSystem("../tests/test_users.json", nullptr);
  
  EXPECT_EQ(userSys->GetPerson(18633084)->GetId(), 18633084);
}


TEST(UserSystemTest, GetMap) {

  UserSystem *userSys = new UserSystem("../tests/test_users.json", nullptr);
  unordered_map<int, Person*> peopleTest = userSys->GetMap();
  EXPECT_EQ(peopleTest[18679479]->GetId(), 18679479); //passwords of test data set
}

TEST(UserSystemTest, GetAPerson) {
  UserSystem *userSys = new UserSystem("../tests/test_users.json", nullptr);
  EXPECT_NE(userSys->GetPerson(18679479), nullptr);
}

TEST(UserSystemTest, GetAFakePerson) {
  UserSystem *userSys = new UserSystem("../tests/test_users.json", nullptr);
  EXPECT_EQ(userSys->GetPerson(7), nullptr);
}

TEST(UserSystemTest, AddAPerson) {
  int hash = 39052307;
  
  UserSystem *userSys = new UserSystem("../tests/test_users.json", nullptr);
  LoginSystem *logSys = new LoginSystem(userSys->GetMap());
  Person* testPerson = new User("steve", 18628694, nullptr, hash);//password is Lskdjf;lksjdgkjdsdg
  userSys->AddPerson(logSys, testPerson);
  EXPECT_EQ(userSys->GetPerson(18628694)->GetId(), 18628694);
}

TEST(UserSystemTest, SaveUserData) {
  UserSystem *userSys = new UserSystem("../tests/test_users.json", nullptr);
  EXPECT_EQ(userSys->GetPerson(18658864)->GetId(),18658864);
}