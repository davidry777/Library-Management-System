#pragma once

#include "gtest/gtest.h"

#include "../header/Book.hpp"
#include "../header/BookSort.hpp"
#include "../header/AlphabeticalSort.hpp"

TEST(SortTest, OneBook)
{
	Book* testBook = new Book("Test", 12345, "Fiction", "NotYou");
	std::vector<Content*> sorted;
	std::unordered_map<long long, Content*> cata;
	cata.insert({12345, testBook});
	AlphabeticalSort* a = new AlphabeticalSort();
	sorted = a->SortBooks(cata);
	EXPECT_EQ(sorted.at(0)->GetAuthor(), "NotYou");
}

TEST(SortTest, TwoBooks)
{
	Book* testBook = new Book("Test", 12345, "Fiction", "NotYou");
	Book* testBook2 = new Book("ATest", 54321, "NonFiction", "NotMe");
	std::vector<Content*> sorted;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
	cata.insert({54321, testBook2});
        AlphabeticalSort* a = new AlphabeticalSort();
        sorted = a->SortBooks(cata);
        EXPECT_EQ(sorted.at(0)->GetAuthor(), "NotMe");
}
TEST(SortTest, TwoBooksAlreadySorted)
{
	Book* testBook = new Book("ATest", 12345, "Fiction", "NotYou");
        Book* testBook2 = new Book("Test", 54321, "NonFiction", "NotMe");
        std::vector<Content*> sorted;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
        cata.insert({54321, testBook2});
        AlphabeticalSort* a = new AlphabeticalSort();
        sorted = a->SortBooks(cata);
        EXPECT_EQ(sorted.at(0)->GetAuthor(), "NotYou");
}
