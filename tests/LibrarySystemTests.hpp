#pragma once

#include "gtest/gtest.h"

#include "../header/LibrarySystem.hpp"

using namespace std;

TEST(LibrarySystemTest, Constructor) {
    LibrarySystem testLibrary("tests/test_catalogue.json", "tests/test_checked_out.json", "tests/test_files/test_users.json");
    UserSystem* us = testLibrary.GetUserSystem();
    BookSystem* bs = testLibrary.GetBookSystem();
    EXPECT_TRUE(us != nullptr && bs != nullptr);
}

TEST(LibrarySystemTest, Destructor) {
    LibrarySystem* testLibrary = new LibrarySystem("tests/test_catalogue.json", "tests/test_checked_out.json", "tests/test_files/test_users.json");
    UserSystem* us = testLibrary->GetUserSystem();
    BookSystem* bs = testLibrary->GetBookSystem();
    delete testLibrary;
    EXPECT_TRUE(us == nullptr && bs == nullptr);
}