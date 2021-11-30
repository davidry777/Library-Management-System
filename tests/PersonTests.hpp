#pragma once

#include "gtest/gtest.h"

#include "../header/LibrarySystem.hpp"
#include "../header/UserSystem.hpp"
#include "../header/BookSystem.hpp"
#include "../header/User.hpp"
#include "../header/Librarian.hpp"
#include "../header/CheckOutData.hpp"

#include <vector>

LibrarySystem* genLib()
{
    UserSystem* userSys = new UserSystem();
    BookSystem* bookSys = new BookSystem("../catalogue.json", "none", "none");
    return new LibrarySystem(userSys, bookSys);
}

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

TEST(UserTest, CheckedOutBooks)
{
    User user("Jason Giese", 28956, genLib(), "~ZD0bRrv~[A/nyP");
    user.CheckoutBook(9781617734076);
    user.CheckoutBook(9781250166609);
    EXPECT_EQ(user.DisplayCheckout(),
        "Title: Getting Away Is Deadly: An Ellie Avery Mystery\n
        ISBN: 9781617734076\n
        Author: Sara Rosett\n
        Genre: Mystery\n
        Frequency: 0\n
        Title: Edgedancer: From the Stormlight Archive\n
        ISBN: 9781250166609\n
        Author: Brandon Sanderson\n
        Genre: Fantasy\n
        Frequency: 0\n");
}

TEST(UserTest, ReturnedBooks)
{
    User user("Jason Giese", 28956, genLib(), "~ZD0bRrv~[A/nyP");
    user.CheckoutBook(9781617734076);
    user.CheckoutBook(9781250166609);
    user.ReturnBook(9781617734076);
    user.ReturnBook(9781250166609);
    EXPECT_EQ(user.DisplayCheckout(),
        "\n");
}

TEST(UserTest, SetCheckedOutData)
{
    User user("Jason Giese", 28956, nullptr, "~ZD0bRrv~[A/nyP");
    std::vector<CheckOutData*> newData;
    newData.push_back(new CheckOutData(365, new Book("Harry Potter and the Goblet Of Fire", 9780747546245, "Fantasy", "J. K. Rowling", 123), user));
    newData.push_back(new CheckOutData(216, new Book("Twilight", 9780316015849, "Fiction", "Stephenie Meyer", 66), user));
    user.SetCheckedOutData(newData);
    EXPECT_EQ(user.DisplayCheckout(),
        "Title: Harry Potter and the Goblet Of Fire\n
        ISBN: 9780747546245\n
        Author: J. K. Rowling\n
        Genre: Fantasy\n
        Frequency: 123\n
        Title: Twilight\n
        ISBN: 9780316015849\n
        Author: Stephenie Meyer\n
        Genre: Fiction\n
        Frequency: 66\n");
}

