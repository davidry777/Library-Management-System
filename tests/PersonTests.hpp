#pragma once

#include "gtest/gtest.h"

#include "../header/BookSystem.hpp"
#include "../header/Book.hpp"
#include "../header/User.hpp"
#include "../header/Librarian.hpp"
#include "../header/CheckOutData.hpp"

#include <iostream>
#include <vector>
#include <string>

TEST(PersonTest, GetName)
{
    User user("Jason Giese", 28956, nullptr, 830264);
    EXPECT_EQ(user.GetName(), "Jason Giese");
}

TEST(PersonTest, GetID)
{
    User user("Jason Giese", 28956, nullptr, 830264);
    EXPECT_EQ(user.GetId(), 28956);
}

TEST(PersonTest, GetPassword)
{
    User user("Jason Giese", 28956, nullptr, 830264);
    EXPECT_EQ(user.GetHashedPassword(), 830264);
}

TEST(PersonTest, GetBookSystem)
{
    BookSystem* setBookSys = new BookSystem("../tests/test_files/test_catalogue.json", "none");
    User user("Jason Giese", 28956, setBookSys, 830264);
    EXPECT_TRUE(user.GetBookSys() == setBookSys);
    delete setBookSys;
}

TEST(UserTest, ZeroBalance)
{
    User user("Jason Giese", 28956, nullptr, 830264);
    EXPECT_EQ(user.GetBalance(), 0);
}

TEST(UserTest, AddedDebt)
{
    User user("Jason Giese", 28956, nullptr, 830264);
    user.PayBalance(-15);
    EXPECT_EQ(user.GetBalance(), 15);
}

TEST(UserTest, RemovedDebt)
{
    User user("Jason Giese", 28956, nullptr, 830264);
    user.PayBalance(-30);
    EXPECT_EQ(user.GetBalance(), 30);
    user.PayBalance(12);
    EXPECT_EQ(user.GetBalance(), 18);
    user.PayBalance(18);
    EXPECT_EQ(user.GetBalance(), 0);
}

TEST(LibrarianTest, AddingBook)
{
    BookSystem* setBookSys = new BookSystem("../tests/test_files/test_catalogue.json", "none");
    Librarian librarian("Gwen Kiler", 78094, setBookSys, 403501);
    Book* book = new Book("How to be a CS God", 9784567290812, "Non Fiction", "David Ryan", 0);
    librarian.AddBook(book);
    EXPECT_EQ(librarian.GetBookSys()->GetContent(9784567290812), book);
    delete setBookSys;
}

TEST(LibrarianTest, RemovingBook)
{
    BookSystem* setBookSys = new BookSystem("../tests/test_files/test_catalogue.json", "none");
    Librarian librarian("Gwen Kiler", 78094, setBookSys, 403501);
    Book* book = new Book("How to be a CS God", 9784567290812, "Non Fiction", "David Ryan", 0);
    librarian.AddBook(book);
    librarian.RemoveBook(9784567290812);
    EXPECT_EQ(librarian.GetBookSys()->GetContent(9784567290812), nullptr);
    delete setBookSys;
}

TEST(LibrarianTest, SettingBookSystem)
{
    Librarian librarian("Gwen Kiler", 78094, nullptr, 403501);
    BookSystem* setBookSys = new BookSystem("../tests/test_files/test_catalogue.json", "none");
    librarian.SetBookSys(setBookSys);
    EXPECT_EQ(librarian.GetBookSys(), setBookSys);
    delete setBookSys;
}
