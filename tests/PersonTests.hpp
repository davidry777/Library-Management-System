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

BookSystem* genBookSys()
{
    return new BookSystem("../tests/test_catalogue.json", "none", "none");
}

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
    BookSystem* setBookSys = new BookSystem("../tests/test_catalogue.json", "none", "none");
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

//TEST(UserTest, CheckedOutBooks)
//{
//    User user("Jason Giese", 28956, genBookSys(), 830264);
//    user.CheckoutBook(9781617734076);
//    user.CheckoutBook(9781250166609);   
//    EXPECT_EQ(user.DisplayCheckOut(), "Title: Getting Away Is Deadly: An Ellie Avery Mystery\nISBN: 9781617734076\nAuthor: Sara Rosett\nGenre: Mystery\nFrequency: 0\nTitle: Edgedancer: From the Stormlight Archive\nISBN: 9781250166609\nAuthor: Brandon Sanderson\nGenre: Fantasy\nFrequency: 0\n");
//}

//TEST(UserTest, ReturnedBooks)
//{
//    User user("Jason Giese", 28956, genBookSys(), 830264);
//    user.CheckoutBook(9781617734076);
//    user.CheckoutBook(9781250166609);
//    user.ReturnBook(9781617734076);
//    user.ReturnBook(9781250166609);
//    EXPECT_EQ(user.DisplayCheckOut(), "\n");
//}

//TEST(UserTest, SetCheckedOutData)
//{
//    User user("Jason Giese", 28956, nullptr, 830264);
//    std::vector<CheckOutData*> newData;
//    newData.push_back(new CheckOutData(365, new Book("Harry Potter and the Goblet Of Fire", 9780747546245, "Fantasy", "J. K. Rowling", 123), user));
//    newData.push_back(new CheckOutData(216, new Book("Twilight", 9780316015849, "Fiction", "Stephenie Meyer", 66), user));
//    user.SetCheckedOutData(newData);
//    EXPECT_EQ(user.DisplayCheckOut(), "Title: Harry Potter and the Goblet Of Fire\nISBN: 9780747546245\nAuthor: J. K. Rowling\nGenre: Fantasy\nFrequency: 123\nTitle: Twilight\nISBN: 9780316015849\nAuthor: Stephenie Meyer\nGenre: Fiction\nFrequency: 66\n");
//}

TEST(LibrarianTest, AddingBook)
{
    BookSystem* setBookSys = new BookSystem("../tests/test_catalogue.json", "none", "none");
    Librarian librarian("Gwen Kiler", 78094, setBookSys, 403501);
    Book* book = new Book("How to be a CS God", 9784567290812, "Non Fiction", "David Ryan", 0);
    librarian.AddBook(book);
    EXPECT_EQ(librarian.GetBookSys()->GetContent(9784567290812), book);
    delete setBookSys;
    delete book;
}

TEST(LibrarianTest, RemovingBook)
{
    BookSystem* setBookSys = new BookSystem("../tests/test_catalogue.json", "none", "none");
    Librarian librarian("Gwen Kiler", 78094, genBookSys(), 403501);
    Book* book = new Book("How to be a CS God", 9784567290812, "Non Fiction", "David Ryan", 0);
    librarian.AddBook(book);
    librarian.RemoveBook(9784567290812);
    EXPECT_EQ(librarian.GetBookSys()->GetContent(9784567290812), nullptr);
    delete setBookSys;
    delete book;   
}

TEST(LibrarianTest, SettingBookSystem)
{
    Librarian librarian("Gwen Kiler", 78094, nullptr, 403501);
    BookSystem* setBookSys = new BookSystem("../tests/test_catalogue.json", "none", "none");
    librarian.SetBookSys(setBookSys);
    EXPECT_EQ(librarian.GetBookSys(), setBookSys);
    delete setBookSys;
}
