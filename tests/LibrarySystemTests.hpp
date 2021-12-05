#pragma once

#include "gtest/gtest.h"

#include "../header/LibrarySystem.hpp"

using namespace std;

TEST(LibrarySystemTest, Constructor) {
    LibrarySystem testLibrary("../tests/test_files/test_catalogue.json", "../tests/test_files/test_checked_out.json", "../tests/test_files/test_users.json");
    EXPECT_TRUE(testLibrary.GetBookSystem()->GetCatalogue().size() == 4 &&
                testLibrary.GetUserSystem()->GetMap().size() == 7 &&
                testLibrary.GetBookSystem()->GetCheckedOut().size() == 2);
}
