#pragma once

#include "gtest/gtest.h"

#include "../header/Content.hpp"
#include "../header/Bundle.hpp"
#include "../header/Book.hpp"

#include <iostream>

TEST(BundleTest, GetAuthor) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("Bundle1", 5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetAuthor(), "Daniel, Gwen, David, Jason");
}
TEST(BundleTest, GetAuthorHalfBlank) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "");
    Bundle testBundle("Bundle1", 5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetAuthor(), "Daniel, Gwen");
}
TEST(BundleTest, GetAuthorBlank) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "");
    Bundle testBundle("Bundle1", 5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetAuthor(), "");
}
TEST(BundleTest, GetTitle) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("Bundle1", 5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetTitle(), "Bundle1");
}
TEST(BundleTest, GetTitleBlank) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("", 5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetTitle(), "");
}
TEST(BundleTest, GetISBN) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("Bundle1", 5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetISBN(), 5);
}
TEST(BundleTest, GetISBNZero) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("Bundle1", 0, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetISBN(), 0);
}
TEST(BundleTest, GetISBNNegative) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("Bundle1", -5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetISBN(), -5);
}
TEST(BundleTest, GetGenre) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("Bundle1", 5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetGenre(), "Fiction");
}
TEST(BundleTest, GetGenreBlank) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("Bundle1", 5, "", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetGenre(), "");
}
TEST(BundleTest, GetFrequencyZero) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("Bundle1", 5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    EXPECT_EQ(testBundle.GetFrequency(), 0);
}
TEST(BundleTest, GetFrequency) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");
    Bundle testBundle("Bundle1", 5, "Fiction", {testBook1, testBook2, testBook3, testBook4});
    testBundle.AddFrequency();
    testBundle.AddFrequency();
    testBundle.AddFrequency();
    EXPECT_EQ(testBundle.GetFrequency(), 3);
}
TEST(BundleTest, Display) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Bundle testBundle("Bundle1", 5, "Fiction", {testBook1, testBook2});
    std::string displayString = "Title: Bundle1\nISBN: 5\nGenre: Fiction\nFrequency: 0\n" + testBook1->Display("\t") + "\n" + testBook2->Display("\t") + "\n";
    EXPECT_EQ(testBundle.Display(), displayString);
} 
TEST(BundleTest, DisplayMultipleBundles) {
    Book* testBook1 = new Book("Book1", 1, "Fiction", "Daniel");
    Book* testBook2 = new Book("Book2", 2, "Fiction", "Gwen");
    Book* testBook3 = new Book("Book3", 3, "Fiction", "David");
    Book* testBook4 = new Book("Book4", 4, "Fiction", "Jason");

    Bundle* testBundle1 = new Bundle("Bundle1", 5, "Fiction", {testBook1, testBook2});
    Bundle* testBundle2 = new Bundle("Bundle2", 6, "Fiction", {testBook3, testBook4});
    Bundle testBundle("Bundle", 7, "Fiction", {testBundle1, testBundle2});

    std::string displayString = "Title: Bundle\nISBN: 7\nGenre: Fiction\nFrequency: 0\n\tTitle: Bundle1\n\tISBN: 5\n\tGenre: Fiction\n\tFrequency: 0\n\t\tTitle: Book1\n\t\tISBN: 1\n\t\tAuthor: Daniel\n\t\tGenre: Fiction\n\t\tFrequency: 0\n\t\tTitle: Book2\n\t\tISBN: 2\n\t\tAuthor: Gwen\n\t\tGenre: Fiction\n\t\tFrequency: 0\n\n\tTitle: Bundle2\n\tISBN: 6\n\tGenre: Fiction\n\tFrequency: 0\n\t\tTitle: Book3\n\t\tISBN: 3\n\t\tAuthor: David\n\t\tGenre: Fiction\n\t\tFrequency: 0\n\t\tTitle: Book4\n\t\tISBN: 4\n\t\tAuthor: Jason\n\t\tGenre: Fiction\n\t\tFrequency: 0\n\n";
    EXPECT_EQ(testBundle.Display(), displayString);
} 