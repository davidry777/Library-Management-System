#include <iostream>
#include <string>

#include "../header/LibrarySystem.hpp"
#include "../header/UserSystem.hpp"
#include "../header/BookSystem.hpp"
#include "../header/Book.hpp"
#include "../header/LoginSystem.hpp"
#include "../header/Person.hpp"
#include "../header/User.hpp"
#include "../header/Librarian.hpp"
#include "../header/DisplaySystem.hpp"

using namespace std;

bool GetLongInput(long long& num) {
    long long n;
    if (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    num = n;
    return true;
}
bool GetIntInput(int& num) {
    int n;
    if (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    num = n;
    return true;
}

bool IsDigitString(const string& str) {
    for (char ch : str)
        if (!isdigit(ch))
            return false;
    return true;
}

void PrintUserInfo(User* user) {
    user->GetInfo();
}

void CheckoutBook(User* person) {
    long long isbn;
    std::cout << "Enter ISBN13 number to check out a book:\n > ";
    if (!GetLongInput(isbn)) {
        cout << "Invalid input! Only input a number.";
        return;
    }
    std::cout << "Checking out book..." << std::endl;
    person->CheckoutBook(isbn);
    std::cout << "Book checked out!" << std::endl;
}

void ReturnBook(User* person) {
    long long isbn;
    std::cout << "Enter ISBN13 number to return a book:\n > ";
    if (!GetLongInput(isbn)) {
        cout << "Invalid input! Only input a number.";
        return;
    }
    std::cout << "Returning book..." << std::endl;
    person->ReturnBook(isbn);
    std::cout << "Book returned!" << std::endl;
}

void ShowDebt(User* person) {
    std::cout << "Amount of debt: $" << person->GetBalance() << std::endl;
}

void PayDebt(User* person) {
    int money;
    std::cout << "Enter how much money you want to pay off:\n > ";
    if (!GetIntInput(money)) {
        cout << "Invalid input! Only input a number.";
        return;
    }
    std::cout << "Paying off $" << money << std::endl;
    person->PayBalance(money);
}

void DisplayCheckedOutBooks(User* person) {
    std::cout << person->GetName() << "'s Checked Out Books:" << std::endl;
    person->DisplayCheckOut();
    std::cout << std::endl;
}

void PrintLibrarianInfo(Librarian* person) {
    person->GetInfo();
}

void AddBook(Librarian* person) {
    std::string title, genre, author, isbnStr = "a";
    long long isbn;

    std::cout << "Enter title for new book:\n > ";
    getline(cin, title);    
    
    std::cout << "Enter ISBN for " << title << ":\n > ";
    if (!GetLongInput(isbn)) {
        cout << "Invalid input! Only input a number.";
        return;
    }

    std::cout << "Enter genre for " << title << ":\n > ";
    getline(cin, genre);
    std::cout << "Enter author for " << title << ":\n > ";
    getline(cin, author);

    Book* newBook = new Book(title, isbn, genre, author, 0);
    person->AddBook(newBook);
    std::cout << title << " added to Librarian " << person->GetName() << "'s library" << std::endl;
}

void RemoveBook(Librarian* person) {
    long long isbn = -1;

    std::cout << "Enter ISBN13 number to remove out a book:\n > ";
    if (!GetLongInput(isbn)) {
        cout << "Invalid input! Only input a number.";
        return;
    }

    std::cout << "Removing book..." << std::endl;
    person->RemoveBook(isbn);
}

void PrintLoginMenu() {
    std::cout << " -------------------- Main Menu -------------------- " << std::endl;
    std::cout << "|           1. Log In                               |" << std::endl;
    std::cout << "|           2. Register an Account                  |" << std::endl;
    std::cout << "|           3. Exit Program                         |" << std::endl;
    std::cout << " --------------------------------------------------- " << std::endl;
    std::cout << "Type an option (1-3):\n > ";
}

void PrintMenu(User* person) {
    std::cout << " ---------------- User Library Menu ---------------- " << std::endl;
    std::cout << "|           1. Display Your Information             |" << std::endl;
    std::cout << "|           2. Check Out a Book                     |" << std::endl;
    std::cout << "|           3. Return a Book                        |" << std::endl;
    std::cout << "|           4. Display Debt From Fines              |" << std::endl;
    std::cout << "|           5. Pay off Debt                         |" << std::endl;
    std::cout << "|           6. Show all Checked Out Books           |" << std::endl;
    std::cout << "|           7. Search/Sort Books                    |" << std::endl;
    std::cout << " --------------------------------------------------- " << std::endl;
    std::cout << "Type an option (1-5). Type -1 to Log Out:\n > ";
}

void PrintMenu(Librarian* person) {
    std::cout << " ------------- Librarian Library Menu -------------- " << std::endl;
    std::cout << "|           1. Display Your Information             |" << std::endl;
    std::cout << "|           2. Add Book to Library                  |" << std::endl;
    std::cout << "|           3. Remove Book from Library             |" << std::endl;
    std::cout << "|           4. Set a New Library                    |" << std::endl;
    std::cout << " --------------------------------------------------- " << std::endl;
    std::cout << "Type an option (1-4). Type -1 to Log Out:\n > ";
}

void DisplayMenu()
{
    std::cout << " ------------ Library Sort/Search Menu ------------- " << std::endl;
    std::cout << "|           1. Search by Genre                      |" << std::endl;
    std::cout << "|           2. Search by KeyWord                    |" << std::endl;
    std::cout << "|           3. Search by ISBN                       |" << std::endl;
    std::cout << "|           4. Sort Alphabetically                  |" << std::endl;
    std::cout << "|           5. Sort by Frequency                    |" << std::endl;
    std::cout << " --------------------------------------------------- " << std::endl;
}

void DisplayHelper(User* person, LibrarySystem* library, int choice)
{
	int input = -1;
	std::string sinput;
	DisplayMenu();
	std::cout << "Type an option (1-5). Type 0 to go back to main menu: ";
	std:: cin >> input;
	std:: cout << std::endl;
	DisplaySystem* display = new DisplaySystem;
	if(input == 1)
	{
		std::cout << "Enter the genre you would like to search for: ";
		std::getline(std::cin, sinput);
		if(choice == 1)
			display->DisplayBooks('1', sinput, library->GetBookSystem()->GetUserCheckedOut(person));	
		if(choice == 2)
			display->DisplayBooks('1', sinput, library->GetBookSystem()->GetCatalogue());
	}
	if(input == 2)
	{
		std::cout << "Enter the keyword you would like to search by: ";
		std::getline(std::cin, sinput);
		if(choice == 1)
			display->DisplayBooks('2', sinput, library->GetBookSystem()->GetUserCheckedOut(person));
		if(choice == 2)
			display->DisplayBooks('2', sinput, library->GetBookSystem()->GetCatalogue());
	}
	if(input == 3)
	{
		// std::cout << "Enter the ISBN you would like to search for: ";
		// std::getline(std::cin, sinput);
		// if(choice == 1)
		// 	display->DisplayBooks('3', ntinput, library->GetBookSystem().GetUserCheckedOut(person));
		// if(choice == 2)
		// 	display->DisplayBooks('3', ntinput, library->GetBookSystem().GetCatalogue());
	}
	if(input == 4)
	{
		if(choice == 1)
			display->DisplayBooks('4', library->GetBookSystem()->GetUserCheckedOut(person));
		if(choice == 2)
			display->DisplayBooks('4', library->GetBookSystem()->GetCatalogue());
	}
	if(input == 5)
	{
		if(choice == 1)
			display->DisplayBooks('5', library->GetBookSystem()->GetUserCheckedOut(person));
		if(choice == 2)
			display->DisplayBooks('5', library->GetBookSystem()->GetCatalogue());
	}
	delete display;
}

void ExecuteCommand(User* person, const string& input) {
    if (input == "1")
        PrintUserInfo(person);
    if (input == "2")
        CheckoutBook(person);
    if (input == "3")
        ReturnBook(person);
    if (input == "4")
        ShowDebt(person);
    if (input == "5")
        PayDebt(person);
    if (input == "6")
        DisplayCheckedOutBooks(person);
    if (input == "7")
	    ;// Search/Sort Books
        
}

void ExecuteCommand(Librarian* librarian, const string& input) {
    if (input == "1")
        PrintLibrarianInfo(librarian);    
    if (input == "2")
        AddBook(librarian);
    if (input == "3")
        RemoveBook(librarian);
    if (input == "4")
        cout << "Work in progress" << endl;
}

int SwitchCaseDisplay(User* person, LibrarySystem* library)
{
	int input = -1;
	std::cout << "Type an option (1-2) [1 to use User Catalogue 2 to use Library Catalogue] Type 0 to go back: ";
	std:: cin >> input;
	if(input == 1)
	   DisplayHelper(person, library, input);
	if(input == 2)
	   DisplayHelper(person, library, input);	
	if(input == 0)
	   return 0;
	return input;
}

int main() {
    Person* currPerson = nullptr;
    string input;
    bool loggedIn = false;
    string catalogueFile, checkedOutFile, userInfoFile;
    
    cout << "Input the catalogue filename (or \"default\" for default filenames):\n > ";
    getline(cin, catalogueFile);
    if (catalogueFile == "default") {
        catalogueFile = "../program_files/catalogue.json"; 
        checkedOutFile = "../program_files/checked_out.json"; 
        userInfoFile = "../program_files/userInfo.json"; 
    }
    else {
        cout << "Input the check out data filename:\n > ";
        getline(cin, checkedOutFile);
        cout << "Input the user info data filename:\n > ";
        getline(cin, userInfoFile);
    }

    LibrarySystem lib(catalogueFile, checkedOutFile, userInfoFile, 86400);

    while (true) { 
        PrintLoginMenu();
        getline(cin, input);
        if (input != "1" && input != "2" && input != "3") { continue; }
        if (input == "3") { break; }
        if (input == "1") {
            // LogIn System here
            // If Log In was successful, set loggedIn = true
        }
        else if (input == "2") {
            // Register System here
        }
        if (loggedIn) {
            if (dynamic_cast<User*>(currPerson) != nullptr)
                while (input != "-1") {
                    PrintMenu(dynamic_cast<User*>(currPerson));
                    getline(cin, input);
                    ExecuteCommand(dynamic_cast<User*>(currPerson), input);
                }
            else if (dynamic_cast<Librarian*>(currPerson) != nullptr)
                while (input != "-1") {
                    PrintMenu(dynamic_cast<Librarian*>(currPerson));
                    getline(cin, input);
                    ExecuteCommand(dynamic_cast<Librarian*>(currPerson), input);
                }
        }
        loggedIn = false;
    }
    cout << "Saving. Do not exit program!" << endl;
    lib.GetBookSystem()->SaveCatalogue();
    cout << "33%" << endl;
    lib.GetBookSystem()->SaveCheckedOut();
    cout << "66%" << endl;
    lib.GetUserSystem()->SaveUserData(userInfoFile);
    cout << "100%" << endl;
    cout << "Program successfully saved. Exiting..." << endl;
    return 0;
}
