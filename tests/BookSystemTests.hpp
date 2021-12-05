#pragma once

#include "gtest/gtest.h"

#include <chrono>
#include <thread>
#include <fstream>

#include "../header/BookSystem.hpp"
#include "../header/User.hpp"
#include "../header/json.hpp"

using namespace std;

TEST(BookSystemTest, Constructor) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_TRUE(testBookSystem.GetCatalogue().size() == 4);
}
TEST(BookSystemTest, GetContentValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_TRUE(testBookSystem.GetContent(9781506713816)->GetTitle() == "The Art of Super Mario Odyssey" &&
                testBookSystem.GetContent(9781506713816)->GetISBN() == 9781506713816 &&
                testBookSystem.GetContent(9781506713816)->GetGenre() == "Activities" &&
                testBookSystem.GetContent(9781506713816)->GetAuthor() == "Nintendo");
}
TEST(BookSystemTest, GetContentInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "none");
    EXPECT_EQ(testBookSystem.GetContent(10101010110), nullptr);
}
TEST(BookSystemTest, AddContentValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.AddContent(new Book("Harry Potter and the Sorcerer's Stone", 9780439362139, "Fantasy", "J. K. Rowling"));
    EXPECT_TRUE(testBookSystem.GetContent(9780439362139)->GetTitle() == "Harry Potter and the Sorcerer's Stone" &&
                testBookSystem.GetContent(9780439362139)->GetISBN() == 9780439362139 &&
                testBookSystem.GetContent(9780439362139)->GetGenre() == "Fantasy" &&
                testBookSystem.GetContent(9780439362139)->GetAuthor() == "J. K. Rowling");
}
TEST(BookSystemTest, AddContentInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    EXPECT_FALSE(testBookSystem.AddContent(new Book("Harry Potter and the Sorcerer's Stone", 9781612626864, "Fantasy", "J. K. Rowling")));
}
TEST(BookSystemTest, MakeBundleValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.MakeBundle("Combo", 1, "variety", {new Book("test", 2, "fantasy", "me"), new Book("test", 3, "fantasy", "me")});
    EXPECT_TRUE(testBookSystem.GetContent(1) != nullptr);
}
TEST(BookSystemTest, MakeBundleInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    EXPECT_FALSE(testBookSystem.MakeBundle("Combo", 9781506713816, "variety", {new Book("test", 2, "fantasy", "me"), new Book("test", 3, "fantasy", "me")}));
}
TEST(BookSystemTest, MakeBundleOfBundle) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.MakeBundle("Bundle1", 123456, "variety", {new Bundle("InnerBundle", 10, "genre", {new Book("test", 3, "fantasy", "me")})});
    EXPECT_TRUE(testBookSystem.GetContent(123456) != nullptr);
}
TEST(BookSystemTest, RemoveContentBookValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.RemoveContent(9781612626864);
    EXPECT_TRUE(testBookSystem.GetContent(9781612626864) == nullptr);
}
TEST(BookSystemTest, RemoveContentBundleValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.MakeBundle("Combo", 1, "variety", {new Book("test", 2, "fantasy", "me"),
                                                      new Book("test", 3, "fantasy", "me")
                                                     }
                             );
    testBookSystem.RemoveContent(1);
    EXPECT_TRUE(testBookSystem.GetContent(1) == nullptr);
}
TEST(BookSystemTest, RemoveContentInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    bool added = testBookSystem.RemoveContent(123);
    EXPECT_FALSE(added);
}
TEST(BookSystemTest, MakeBundleOfBundleAuthors) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.MakeBundle("Bundle1", 1, "variety", {new Bundle("InnerBundle", 2, "genre", {
                                                            new Book("test", 3, "fantasy", "Daniel"),
                                                            new Book("test", 4, "fantasy", "Gwen")
                                                            }),
                                                        new Bundle("InnerBundle", 5, "genre", {
                                                            new Book("test", 6, "fantasy", "David"), 
                                                            new Book("test", 7, "fantasy", "Jason")
                                                            })
                                                        }
                            );
    EXPECT_EQ(testBookSystem.GetContent(1)->GetAuthor(), "Daniel, Gwen, David, Jason");
}
TEST(BookSystemTest, CheckOutValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    User* me = new User("Daniel", 100, nullptr, 2132321);
    EXPECT_TRUE(testBookSystem.CheckOut(me, 9781506713816));
    delete me;
}
TEST(BookSystemTest, CheckOutValidCheckQueue) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    User* me = new User("Daniel", 100, nullptr, 2132321);   // Person* me = new User() LEAKS BC VECTOR IN USER
    testBookSystem.CheckOut(me, 9781506713816);
    EXPECT_TRUE(me->GetCheckedOut().front()->contentCheckedOut->GetISBN() == 9781506713816 &&
                me->GetCheckedOut().front()->userCheckedOut == me &&
                me->GetCheckedOut().front()->overTime == false &&
                me->GetCheckedOut().front()->timeCheckedOut <= time(0) &&
                me->GetCheckedOut().front()->contentCheckedOut->GetISBN() == 9781506713816
                );
    delete me;
}
TEST(BookSystemTest, CheckOutInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    User* me = new User("Daniel", 100, nullptr, 2132321);
    EXPECT_FALSE(testBookSystem.CheckOut(me, 321));
    delete me;
}
TEST(BookSystemTest, ReturnContentValid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    User* me = new User("Daniel", 100, nullptr, 2132321);
    testBookSystem.CheckOut(me, 9781506713816);
    EXPECT_TRUE(testBookSystem.ReturnContent(me, 9781506713816));
    delete me;
}
TEST(BookSystemTest, ReturnContentInvalid) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    User* me = new User("Daniel", 100, nullptr, 2132321);
    EXPECT_FALSE(testBookSystem.ReturnContent(me, 100));
    delete me;
}
TEST(BookSystemTest, CheckExpirationNotExpired) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    User* me = new User("Daniel", 100, nullptr, 2132321);
    testBookSystem.CheckOut(me, 9781506713816);
    testBookSystem.CheckExpiration();
    EXPECT_EQ(testBookSystem.GetCheckedOut().at(100).at(0)->overTime, false);
    delete me;
}
TEST(BookSystemTest, CheckExpirationExpired) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json", 1);
    User* me = new User("Daniel", 100, nullptr, 2132321);
    testBookSystem.CheckOut(me, 9781506713816);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    testBookSystem.CheckExpiration();
    EXPECT_EQ(testBookSystem.GetCheckedOut().at(100).at(0)->overTime, true);
    delete me;
}
TEST(BookSystemTest, SaveCatalogue) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.SaveCatalogue("../tests/output.json");
    
    BookSystem testBookSystem2("../tests/output.json", "test_files/test_checked_out.json");
    EXPECT_TRUE(testBookSystem.GetContent(9781506713816) != nullptr && testBookSystem.GetCatalogue().size() == 4);
}
TEST(BookSystemTest, SaveCatalogueAddedBooks) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    testBookSystem.AddContent(new Book("Harry Potter and the Sorcerer's Stone", 9780439362100, "Fantasy", "J. K. Rowling"));
    testBookSystem.AddContent(new Book("Harry Potter and the Chamber of Secrets", 978043936200, "Fantasy", "J. K. Rowling"));
    testBookSystem.AddContent(new Book("Harry Potter and the Prisoner of Azkaban", 9780439362300, "Fantasy", "J. K. Rowling"));
    testBookSystem.SaveCatalogue("../tests/output.json");
    
    BookSystem testBookSystem2("../tests/output.json", "test_files/test_checked_out.json");
    EXPECT_TRUE(testBookSystem2.GetContent(9780439362300) != nullptr &&
                testBookSystem2.GetContent(9780439362300) != nullptr &&
                testBookSystem2.GetContent(9780439362300) != nullptr &&
                testBookSystem2.GetCatalogue().size() == 7);
}
TEST(BookSystemTest, SaveCheckedOut) {
    BookSystem testBookSystem("../tests/test_catalogue.json", "test_files/test_checked_out.json");
    User* me = new User("Daniel", 100, nullptr, 2132321);
    testBookSystem.CheckOut(me, 9781506713816);
    testBookSystem.SaveCheckedOut("../tests/output.json");
    EXPECT_TRUE(true);
    nlohmann::json jsonParcer;
    ifstream inFS("../tests/output.json");
    inFS >> jsonParcer;
    cout << jsonParcer[0]["user_id"] << " " << jsonParcer[0]["content_isbn"] << " " << jsonParcer[0]["over_time"] << endl;
    EXPECT_TRUE(jsonParcer[0]["user_id"] == 100 &&
                jsonParcer[0]["content_isbn"] == 9781506713816 &&
                jsonParcer[0]["over_time"] == false
                );
    delete me;
}