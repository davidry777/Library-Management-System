#pragma once

#include "gtest/gtest.h"

#include "../header/Book.hpp"

TEST(BookTest, GetAuthor) {
    Book testBook("Test", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetAuthor(), "Me");
}
TEST(BookTest, GetAuthorBlank) {
    Book testBook("Test", 1, "Fiction", "");
    EXPECT_EQ(testBook.GetAuthor(), "");
}
TEST(BookTest, GetTitle) {
    Book testBook("Test", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetTitle(), "Test");
}
TEST(BookTest, GetTitleBlank) {
    Book testBook("", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetTitle(), "");
}
TEST(BookTest, GetISBN) {
    Book testBook("Test", 4531421, "Fiction", "Me");
    EXPECT_EQ(testBook.GetISBN(), 4531421);
}
TEST(BookTest, GetISBNZero) {
    Book testBook("", 0, "Fiction", "Me");
    EXPECT_EQ(testBook.GetISBN(), 0);
}
TEST(BookTest, GetISBNNegative) {
    Book testBook("", -42141, "Fiction", "Me");
    EXPECT_EQ(testBook.GetISBN(), -42141);
}
TEST(BookTest, GetGenre) {
    Book testBook("Test", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetGenre(), "Fiction");
}
TEST(BookTest, GetISBNBlank) {
    Book testBook("", 1, "", "Me");
    EXPECT_EQ(testBook.GetGenre(), "");
}
TEST(BookTest, GetFrequencyZero) {
    Book testBook("", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetFrequency(), 0);
}
TEST(BookTest, GetFrequency) {
    Book testBook("Test", 4531421, "Fiction", "Me");
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    EXPECT_EQ(testBook.GetFrequency(), 5);
}
TEST(BookTest, Display) {
    Book testBook("TestBook", 24142, "Fiction", "Daniel");
    std::string outputString = "Title: TestBook\nISBN: 24142\nAuthor: Daniel\nGenre: Fiction\nFrequency: 0";
    EXPECT_EQ(testBook.Display(), outputString);
} 
TEST(BookTest, DisplayMultipleFrequencies) {
    Book testBook("TestBook", 24142, "Fiction", "Daniel");
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    std::string outputString = "Title: TestBook\nISBN: 24142\nAuthor: Daniel\nGenre: Fiction\nFrequency: 5";
    EXPECT_EQ(testBook.Display(), outputString);
} 