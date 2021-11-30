#pragma once

#include "gtest/gtest.h"

#include "../header/BookSystem.hpp"

TEST(BookSystemTest, Constructor) {
    BookSystem testBookSystem("tests/test_files/test_catalogue.json", "none", "none");
    EXPECT_TRUE(testBookSystem.GetCatalogue().size() != 0);
}
TEST(BookSystemTest, GetContentValid) {
    BookSystem testBookSystem("tests/test_files/test_catalogue.json", "none", "none");
    EXPECT_TRUE(testBookSystem.GetContent(9781612626864) != nullptr);
}
TEST(BookSystemTest, GetContentValidAuthor) {
    BookSystem testBookSystem("tests/test_files/test_catalogue.json", "none", "none");
    EXPECT_EQ(testBookSystem.GetContent(9781612626864)->GetAuthor(), "Hijime Isayama");
}
TEST(BookSystemTest, GetContentValidFrequency) {
    BookSystem testBookSystem("tests/test_files/test_catalogue.json", "none", "none");
    EXPECT_EQ(testBookSystem.GetContent(9781612626864)->GetFrequency(), 0);
}
TEST(BookSystemTest, GetContentValidGenre) {
    BookSystem testBookSystem("tests/test_files/test_catalogue.json", "none", "none");
    EXPECT_EQ(testBookSystem.GetContent(9781612626864)->GetGenre(), "Fantasy");
}
TEST(BookSystemTest, GetContentValidTitle) {
    BookSystem testBookSystem("tests/test_files/test_catalogue.json", "none", "none");
    EXPECT_EQ(testBookSystem.GetContent(9781612626864)->GetTitle(), "Attack on Titan: Volume 13");
}
TEST(BookSystemTest, GetContentInvalid) {
    BookSystem testBookSystem("tests/test_files/test_catalogue.json", "none", "none");
    EXPECT_EQ(testBookSystem.GetContent(10101010110), nullptr);
}
TEST(BookSystemTest, AddContentValid) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    testBookSystem.AddContent(new Book("Harry Potter and the Sorcerer's Stone", 9780439362139, "Fantasy", "J. K. Rowling"));
    EXPECT_TRUE(testBookSystem.GetContent(9780439362139) != nullptr);
}
TEST(BookSystemTest, AddContentValidTitle) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    testBookSystem.AddContent(new Book("Harry Potter and the Sorcerer's Stone", 9780439362139, "Fantasy", "J. K. Rowling"));
    EXPECT_EQ(testBookSystem.GetContent(9780439362139)->GetTitle(), "Harry Potter and the Sorcerer's Stone");
}
TEST(BookSystemTest, AddContentInvalid) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    Content* newBook = new Book("Harry Potter and the Sorcerer's Stone", 9781612626864, "Fantasy", "J. K. Rowling");
    bool added = testBookSystem.AddContent(newBook);
    EXPECT_FALSE(added);
    if (!added)
        delete newBook;
}
TEST(BookSystemTest, RemoveContentValid) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    testBookSystem.RemoveContent(9781612626864);
    EXPECT_TRUE(testBookSystem.GetContent(9781612626864) == nullptr);
}
TEST(BookSystemTest, RemoveContentInvalid) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    bool added = testBookSystem.RemoveContent(123);
    EXPECT_FALSE(added);
}
TEST(BookSystemTest, MakeBundleValid) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    testBookSystem.MakeBundle("Combo", 12345, "variety", {9781612626864, 9780758272799});
    EXPECT_TRUE(testBookSystem.GetContent(12345) != nullptr);
}
TEST(BookSystemTest, MakeBundleInvalid) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    bool added = testBookSystem.MakeBundle("Combo", 9781506713816, "variety", {9781612626864, 9780758272799});
    EXPECT_FALSE(added);
}
TEST(BookSystemTest, MakeBundleOfBundle) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    testBookSystem.MakeBundle("Bundle1", 123456, "variety", {9781612626864, 9780758272799});
    testBookSystem.MakeBundle("Bundle2", 12345, "variety", {123456, 9781506713816});
    EXPECT_TRUE(testBookSystem.GetContent(12345) != nullptr);
}
TEST(BookSystemTest, MakeBundleOfBundleAuthors) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    testBookSystem.MakeBundle("Bundle1", 123456, "variety", {9781612626864, 9780758272799});
    testBookSystem.MakeBundle("Bundle2", 12345, "variety", {123456, 9781506713816});
    EXPECT_EQ(testBookSystem.GetContent(12345)->Display(), "Hijime Isayama, Barbara Allan, Nintendo");
}
TEST(BookSystemTest, CheckOutValid) {
    BookSystem testBookSystem("test_files/test_catalogue.json", "test_files/test_checked_out.json", "test_files/test_passed_due.json");
    Person* me = new User("Daniel", 100, nullptr, "########");
    CheckOutData* = testBookSystem.CheckOut()
}

