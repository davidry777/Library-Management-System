#pragma once

#include "gtest/gtest.h"

#include "../header/User.hpp"
#include "../header/Librarian.hpp"

TEST(UserTest, ZeroBalance)
{
    User user("Jason Giese", 28956, nullptr, "~ZD0bRrv~[A/nyP");
    EXPECT_EQ(user.GetBalance(), 0);
}

TEST(UserTest, AddedDebt)
{
    User user("Jason Giese", 28956, nullptr, "~ZD0bRrv~[A/nyP");
    user.PayBalance(-15)
    EXPECT_EQ(user.GetBalance(), 15);
}

TEST(UserTest, RemovedDebt)
{
    User user("Jason Giese", 28956, nullptr, "~ZD0bRrv~[A/nyP");
    user.PayBalance(-30);
    EXPECT_EQ(user.GetBalance(), 30);
    user.PayBalance(12);
    EXPECT_EQ(user.GetBalance(), 18);
    user.PayBalance(18);
    EXPECT_EQ(user.GetBalance(), 0);
}

TEST(UserTest, DisplayCheckedOutBooks)
{
    User user("Jason Giese", 28956, nullptr, "~ZD0bRrv~[A/nyP");

}

