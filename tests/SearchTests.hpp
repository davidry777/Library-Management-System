#pragma once

#include "gtest/gtest.h"

#include "../header/Book.hpp"
#include "../header/GenreSearch.hpp"
#include "../header/ISBNSearch.hpp"
#include "../header/KeyWordSearch.hpp"

TEST(GenreSearchTest, OneBook)
{
	Book* testBook = new Book("Test", 12345, "Fiction", "NotI");
	std::vector<Content*> searched;
	std::unordered_map<long long, Content*> cata;
	cata.insert({12345, testBook});
	GenreSearch* g = new GenreSearch();
	searched = g->SearchBooks(cata, "Fiction");
	EXPECT_EQ(searched.at(0)->GetAuthor(), "NotI");
}

TEST(GenreSearchTest, TwoBooks)
{
        Book* testBook = new Book("Test", 12345, "Fiction", "NotI");
        Book* testBook2 = new Book("Test", 12346, "Fiction", "NotHe");
	std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
	cata.insert({12346, testBook2});
        GenreSearch* g = new GenreSearch();
        searched = g->SearchBooks(cata, "Fiction");
        EXPECT_EQ(searched.at(0)->GetAuthor(), "NotHe");
	EXPECT_EQ(searched.at(1)->GetAuthor(), "NotI");
}

TEST(GenreSearchTest, TwoBooksOneMatch)
{
        Book* testBook = new Book("Test", 12345, "Fiction", "NotI");
        Book* testBook2 = new Book("Test", 12346, "Nonfiction", "NotHe");
        std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
        cata.insert({12346, testBook2});
        GenreSearch* g = new GenreSearch();
        searched = g->SearchBooks(cata, "Fiction");
        EXPECT_EQ(searched.at(0)->GetAuthor(), "NotI");
}

TEST(GenreSearchTest, NoMatch)
{
        Book* testBook = new Book("Test", 12345, "Fiction", "NotI");
        Book* testBook2 = new Book("Test", 12346, "Fiction", "NotHe");
        std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
        cata.insert({12346, testBook2});
        GenreSearch* g = new GenreSearch();
        searched = g->SearchBooks(cata, "BadGenre");
        EXPECT_EQ(searched.empty(), true);
}

TEST(ISBNSearchTest, OneBook)
{
	Book* testBook = new Book("Test", 12345, "Fiction", "NotI");
        std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
	cata.insert({12345, testBook});
        ISBNSearch* i = new ISBNSearch();
        searched = i->SearchBooks(cata, 12345);
        EXPECT_EQ(searched.at(0)->GetAuthor(), "NotI");
}

TEST(ISBNSearchTest, TwoBooks)
{
        Book* testBook = new Book("Test", 12345, "Fiction", "NotI");
	Book* testBook2 = new Book("Test", 12346, "Fiction", "NotHe");	 
        std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
	cata.insert({12346, testBook2});
        ISBNSearch* i = new ISBNSearch();
        searched = i->SearchBooks(cata, 12346);
        EXPECT_EQ(searched.at(0)->GetAuthor(), "NotHe");
}

TEST(ISBNSearchTest, NoMatch)
{
        Book* testBook = new Book("Test", 12345, "Fiction", "NotI");
        Book* testBook2 = new Book("Test", 12346, "Fiction", "NotHe");
        std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
        cata.insert({12346, testBook2});
        ISBNSearch* i = new ISBNSearch();
        searched = i->SearchBooks(cata, 99999);
        EXPECT_EQ(searched.empty(), true);
}

TEST(KeyWordSearchTest, OneBook)
{
	Book* testBook = new Book("ThisIsATestTitle", 12345, "Fiction", "NotI");
        std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
        KeyWordSearch* k = new KeyWordSearch();
        searched = k->SearchBooks(cata, "Test");
        EXPECT_EQ(searched.at(0)->GetAuthor(), "NotI");
}

TEST(KeyWordSearchTest, TwoBooks)
{
	Book* testBook = new Book("ThisIsATestTitle", 12345, "Fiction", "NotI");
        Book* testBook2 = new Book("ThisIsAlsoATestTitle", 123456, "Fiction", "NotThey");
	std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
	cata.insert({123456, testBook2});
        KeyWordSearch* k = new KeyWordSearch();
        searched = k->SearchBooks(cata, "Test");
        EXPECT_EQ(searched.at(0)->GetAuthor(), "NotThey");
	EXPECT_EQ(searched.at(1)->GetAuthor(), "NotI");
}

TEST(KeyWordSearch, TwoBooksOneMatch)
{
	Book* testBook = new Book("ThisIsATestTitle", 12345, "Fiction", "NotI");
        Book* testBook2 = new Book("ThisIsAlsoATestTitle", 123456, "Fiction", "NotThey");
        std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
        cata.insert({123456, testBook2});
        KeyWordSearch* k = new KeyWordSearch();
        searched = k->SearchBooks(cata, "Also");
        EXPECT_EQ(searched.at(0)->GetAuthor(), "NotThey");
}

TEST(KeyWordSearchTest, NoMatch)
{
Book* testBook = new Book("ThisIsATestTitle", 12345, "Fiction", "NotI");
        Book* testBook2 = new Book("ThisIsAlsoATestTitle", 123456, "Fiction", "NotThey");
        std::vector<Content*> searched;
        std::unordered_map<long long, Content*> cata;
        cata.insert({12345, testBook});
        cata.insert({123456, testBook2});
        KeyWordSearch* k = new KeyWordSearch();
        searched = k->SearchBooks(cata, "DefinitelyNotInHere");
        EXPECT_EQ(searched.empty(), true);
}
