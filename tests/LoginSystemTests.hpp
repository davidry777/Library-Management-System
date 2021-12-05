#pragma once

#include <fstream>
#include "gtest/gtest.h"
#include "../header/LoginSystem.hpp"
#include "../header/UserSystem.hpp"
TEST(LoginSystemTest, Construct) {
  UserSystem *userSys = new UserSystem("../tests/test_files/test_users.json", nullptr);
  LoginSystem *logSys = new LoginSystem(userSys->GetMap());
  EXPECT_EQ(logSys->GetHashPass(18658864), 11464202);
    delete userSys;
delete logSys;
}
TEST(LoginSystemTest, LoginVerify) {
  UserSystem *userSys = new UserSystem("../tests/test_files/test_users.json", nullptr);
  LoginSystem *logSys = new LoginSystem(userSys->GetMap());
  int ID = 18658864;
  string pass = "Applesauce";
  EXPECT_TRUE(logSys->LoginVerify(ID, pass));
  delete userSys;
delete logSys;
}
TEST(LoginSystemTest, LoginVerifyFailure) {
  UserSystem *userSys = new UserSystem("../tests/test_files/test_users.json", nullptr);
  LoginSystem *logSys = new LoginSystem(userSys->GetMap());
  int ID = 18658864;
  string pass = "wrong password";
  EXPECT_FALSE(logSys->LoginVerify(ID, pass));
  delete userSys;
delete logSys;
}
TEST(LoginSystemTest, SavedHash) {
  UserSystem *userSys = new UserSystem("../tests/test_files/test_users.json", nullptr);
  LoginSystem *logSys = new LoginSystem(userSys->GetMap());  
  int ID = 34;
  int pass = 89000;
  logSys->AddPass(34, 89000);
  EXPECT_EQ(logSys->GetHashPass(34), 89000);
  delete userSys;
delete logSys;
}
TEST(LoginSystemTest, EmptyHash) {
  UserSystem *userSys = new UserSystem("../tests/test_files/test_users.json", nullptr);
  LoginSystem *logSys = new LoginSystem(userSys->GetMap());  int ID = 34;  
  string pass = ""; //39052307
  EXPECT_EQ(logSys->HashPassword(pass),0);
  delete userSys;
delete logSys;
}

TEST(LoginSystemTest, GetHashPass) {
  UserSystem *userSys = new UserSystem("../tests/test_files/test_users.json", nullptr);
  LoginSystem *logSys = new LoginSystem(userSys->GetMap());  int ID = 34;  
  string pass = "Lskdjf;lksjdgkjdsdg"; //39052307
  EXPECT_EQ(logSys->HashPassword(pass),39052307);
  delete userSys;
delete logSys;
}

