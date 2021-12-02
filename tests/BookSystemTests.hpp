#pragma once

#include "gtest/gtest.h"

#include "../header/BookSystem.hpp"
#include "../header/User.hpp"

using namespace std;

TEST(BookSystemTest, Constructor) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_TRUE(testBookSystem.GetCatalogue().size() != 0);
}
TEST(BookSystemTest, GetContentValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_TRUE(testBookSystem.GetContent(9781612626864) != nullptr);
}
TEST(BookSystemTest, GetContentValidAuthor) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_EQ(testBookSystem.GetContent(9781612626864)->GetAuthor(), "Hajime Isayama");
}
TEST(BookSystemTest, GetContentValidFrequency) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_EQ(testBookSystem.GetContent(9781612626864)->GetFrequency(), 0);
}
TEST(BookSystemTest, GetContentValidGenre) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_EQ(testBookSystem.GetContent(9781612626864)->GetGenre(), "Fantasy");
}
TEST(BookSystemTest, GetContentValidTitle) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_EQ(testBookSystem.GetContent(9781612626864)->GetTitle(), "Attack on Titan: Volume 13");
}
TEST(BookSystemTest, GetContentInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_EQ(testBookSystem.GetContent(10101010110), nullptr);
}
TEST(BookSystemTest, AddContentValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.AddContent(new Book("Harry Potter and the Sorcerer's Stone", 9780439362139, "Fantasy", "J. K. Rowling"));
    EXPECT_TRUE(testBookSystem.GetContent(9780439362139) != nullptr);
}
TEST(BookSystemTest, AddContentValidTitle) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.AddContent(new Book("Harry Potter and the Sorcerer's Stone", 9780439362139, "Fantasy", "J. K. Rowling"));
    EXPECT_EQ(testBookSystem.GetContent(9780439362139)->GetTitle(), "Harry Potter and the Sorcerer's Stone");
}
TEST(BookSystemTest, AddContentInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    Content* newBook = new Book("Harry Potter and the Sorcerer's Stone", 9781612626864, "Fantasy", "J. K. Rowling");
    bool added = testBookSystem.AddContent(newBook);
    EXPECT_FALSE(added);
    if (!added)
        delete newBook;
}
TEST(BookSystemTest, RemoveContentValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.RemoveContent(9781612626864);
    EXPECT_TRUE(testBookSystem.GetContent(9781612626864) == nullptr);
}
TEST(BookSystemTest, RemoveContentInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    bool added = testBookSystem.RemoveContent(123);
    EXPECT_FALSE(added);
}
TEST(BookSystemTest, MakeBundleValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.MakeBundle("Combo", 1, "variety", {new Book("test", 2, "fantasy", "me"), new Book("test", 3, "fantasy", "me")});
    EXPECT_TRUE(testBookSystem.GetContent(1) != nullptr);
}
TEST(BookSystemTest, MakeBundleInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    bool added = testBookSystem.MakeBundle("Combo", 9781506713816, "variety", {new Book("test", 2, "fantasy", "me"), new Book("test", 3, "fantasy", "me")});
    EXPECT_FALSE(added);
}
TEST(BookSystemTest, MakeBundleOfBundle) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.MakeBundle("Bundle1", 123456, "variety", {new Bundle("InnerBundle", 10, "genre", {new Book("test", 3, "fantasy", "me")})});
    EXPECT_TRUE(testBookSystem.GetContent(123456) != nullptr);
}
TEST(BookSystemTest, MakeBundleOfBundleAuthors) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.MakeBundle("Bundle1", 123456, "variety", {new Bundle("InnerBundle", 10, "genre", {new Book("test", 3, "fantasy", "me")})});
    EXPECT_EQ(testBookSystem.GetContent(123456)->GetAuthor(), "me");
}
TEST(BookSystemTest, CheckOutValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    Person* me = new User("Daniel", 100, nullptr, 2132321);
    EXPECT_TRUE(testBookSystem.CheckOut(me, 9781506713816) != nullptr);
    delete me;
}
TEST(BookSystemTest, CheckOutValidCheckQueue) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    Person* me = new User("Daniel", 100, nullptr, 2132321);
    testBookSystem.CheckOut(me, 9781506713816);
    EXPECT_EQ((*testBookSystem.GetCheckedOut().at(100).begin())->contentCheckedOut->GetISBN(), 9781506713816);
    delete me;
}
TEST(BookSystemTest, CheckOutInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    Person* me = new User("Daniel", 100, nullptr, 2132321);
    EXPECT_TRUE(testBookSystem.CheckOut(me, 321) == nullptr);
    delete me;
}
TEST(BookSystemTest, ReturnContentValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    Person* me = new User("Daniel", 100, nullptr, 2132321);
    testBookSystem.CheckOut(me, 9781506713816);
    EXPECT_TRUE(testBookSystem.ReturnContent(me, 9781506713816));
    delete me;
}
TEST(BookSystemTest, ReturnContentInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    Person* me = new User("Daniel", 100, nullptr, 2132321);
    EXPECT_FALSE(testBookSystem.ReturnContent(me, 100));
    delete me;
}
TEST(BookSystemTest, SaveCatalogue) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.AddContent(new Book("Harry Potter and the Sorcerer's Stone", 9780439362139, "Fantasy", "J. K. Rowling"));
    testBookSystem.SaveCatalogue("../tests/output.json");
    
    BookSystem testBookSystem2("../tests/output.json", "test_files/test_checked_out.json");
    EXPECT_TRUE(testBookSystem.GetContent(9780439362139) != nullptr);
}