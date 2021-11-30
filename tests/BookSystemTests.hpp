#pragma once

#include "gtest/gtest.h"

#include "../header/BookSystem.hpp"

TEST(BookSystemTest, Constructor) {
    BookSystem testBookSystem("tests/test_files/test_catalogue.json", "none", "none");
    EXPECT_TRUE(testBookSystem.GetCatalogue().size() != 0);
}