#pragma once

#include "gtest/gtest.h"

#include "../header/Book.hpp"
#include "../header/AlphabeticalSort.hpp"

TEST(AlphabeticalSortTest, OneBook)
{
	Book* testBook = new Book("Test", 12345, "Fiction", "NotYou");
	std::vector<Content*> sorted;
	std::unordered_map<long long, Content*> cata;
	cata.insert({12345, testBook});
	AlphabeticalSort* a = new AlphabeticalSort();
	sorted = a->SortBooks(cata);
	EXPECT_EQ(sorted.at(0)->GetAuthor(), "NotYou");
}

TEST(AlphabeticalSortTest, TwoBooks)
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
TEST(AlphabeticalSortTest, TwoBooksAlreadySorted)
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

TEST(AlphabeticalSortTest, FourBooks)
{
	Book* testBook = new Book("CTest", 12345, "Fiction", "NotYou");
        Book* testBook2 = new Book("DTest", 54321, "NonFiction", "NotMe");
	Book* testBook3 = new Book("BTest", 12346, "History", "NotI");
        Book* testBook4 = new Book("ATest", 64321, "Fiction", "NotThey");
	std::vector<Content*> sorted;
	std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
        cata.insert({54321, testBook2});
	cata.insert({12346, testBook3});
	cata.insert({64321, testBook4});
        AlphabeticalSort* a = new AlphabeticalSort();
        sorted = a->SortBooks(cata);
        EXPECT_EQ(sorted.at(0)->GetAuthor(), "NotThey");	
}
