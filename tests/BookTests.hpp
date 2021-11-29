#pragma once

#include "gtest/gtest.h"

#include "../header/Book.hpp"

TEST(BookTest, BookGetAuthor) {
    Book testBook("Test", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetAuthor(), "Me");
}
TEST(BookTest, BookGetAuthorBlank) {
    Book testBook("Test", 1, "Fiction", "");
    EXPECT_EQ(testBook.GetAuthor(), "");
}
TEST(BookTest, BookGetTitle) {
    Book testBook("Test", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetTitle(), "Test");
}
TEST(BookTest, BookGetTitleBlank) {
    Book testBook("", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetTitle(), "");
}
TEST(BookTest, BookGetISBN) {
    Book testBook("Test", 4531421, "Fiction", "Me");
    EXPECT_EQ(testBook.GetISBN(), 4531421);
}
TEST(BookTest, BookGetISBNZero) {
    Book testBook("", 0, "Fiction", "Me");
    EXPECT_EQ(testBook.GetISBN(), 0);
}
TEST(BookTest, BookGetISBNNegative) {
    Book testBook("", -42141, "Fiction", "Me");
    EXPECT_EQ(testBook.GetISBN(), -42141);
}
TEST(BookTest, BookGetGenre) {
    Book testBook("Test", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetGenre(), "Fiction");
}
TEST(BookTest, BookGetISBNBlank) {
    Book testBook("", 1, "", "Me");
    EXPECT_EQ(testBook.GetGenre(), "");
}
TEST(BookTest, BookGetFrequencyZero) {
    Book testBook("", 1, "Fiction", "Me");
    EXPECT_EQ(testBook.GetFrequency(), 0);
}
TEST(BookTest, BookGetFrequency) {
    Book testBook("Test", 4531421, "Fiction", "Me");
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    EXPECT_EQ(testBook.GetFrequency(), 5);
}
TEST(BookTest, BookDisplay) {
    Book testBook("TestBook", 24142, "Fiction", "Daniel");
    std::string outputString = "Title: TestBook\nISBN: 24142\nAuthor: Daniel\nGenre: Fiction\nFrequency: 0";
    EXPECT_EQ(testBook.Display(), outputString);
} 
TEST(BookTest, BookDisplayMultipleFrequencies) {
    Book testBook("TestBook", 24142, "Fiction", "Daniel");
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    testBook.AddFrequency();
    std::string outputString = "Title: TestBook\nISBN: 24142\nAuthor: Daniel\nGenre: Fiction\nFrequency: 5";
    EXPECT_EQ(testBook.Display(), outputString);
} 