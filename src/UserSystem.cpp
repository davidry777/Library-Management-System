#include "../header/UserSystem.hpp"
#include "../header/Person.hpp"
#include "../header/LoginSystem.hpp"
#include <fstream>
#include <../header/CheckOutData.hpp>
#include <ctime>
#include <header/json.hpp>

using namespace std;

Person* UserSystem::GetPerson(int ID)
{
	return this->people[ID];
}

UserSystem::UserSystem(vector<CheckOutData*>& checkedOut, deque<CheckOutData*>& passedDue	)
{
	//import users from a file to populate the array
	ifstream people_file("userInfo.json");
	json readJson;
	json readCheckedOut;
	ifstream checkout("checked_out.json");
	checkout >> readCheckedOut;
	people_file >> readJson;
	unordered_map<int, Person*> userMap;
	for (auto it : readJson)
	{
		int debt;
		vector<CheckOutData*> checkoutData;
		int ID = it.key();
		string name = readJson["users"][ID]["name"].value();
		int hashPass = readJson["users"][ID]["hashPass"].value();
		if (readJson["users"][ID].find("debt"] != readJson.end()))
		{
			debt = readJson["users"][ID]["debt"].value();
			User* tempUser(name, ID);
			tempUser.PayBalance(-1*debt);
			for (auto book : checkedOut)
			{
				if (book->userCheckedOut.GetID() == ID)
				{
					checkoutData.push_back(book);
				}
			}
			for (auto book : passedDue)
			{
				if (book->userCheckedOut.GetID() == ID)
					checkoutData.push_back(book);
			}
			tempUser.SetCheckedOutData(checkoutData);
			/*for (json::iterator ite = readJson["users"][ID].begin()+2; ite != readJson.end(); ++ite)
			{
				long long tempISBN = ite.key();
				time_t tempTime = readJson["users"][ID][tempISBN]["timeCheckedOut"];
				bool tempOver = readJson["users"][ID][tempISBN]["overTime"];
				Content tempContent = GetContent(tempISBN);
				CheckOutData tempData(tempTime, tempContent, tempUser);
				checkoutData.push_back(tempData);
			}
			tempUser.SetCheckedOutData(checkoutData);*/
			userMap[ID] = tempUser;
		}
		else
		{
			Librarian* tempLibrarian(name, ID);
			userMap[ID] = tempLibrarian;
		}
		
	}
	this->people = userMap;
	people_file.close();	
}
UserSystem::~UserSystem()
{
	for (auto &x : users)
		delete x;
}

//Person* UserSystem::SetCurrPerson(Person *dude, string password) {
//	if (LoginVerify(dude->ID, password, users))
//		return dude;
//	else
//		return nullptr;
//}

void UserSystem::AddPerson(Person *dude) {
	this->users.insert({ dude.get, dude });	
}

void UserSystem::SaveUserData()
{
	json userInfo;
	
	vector<CheckOutData*> tempVec;
	for (const auto & [ID, userPerson] : users)
	{
		userInfo["users"][userPerson.GetID()]["hashPass"] = GetHashPass(userPerson.GetID); //TODO
		userInfo["users"][userPerson.GetID()]["name"] = userPerson.GetName();
		if (dynamic_cast<User*> (userPerson) != nullptr)
		{
			userInfo["users"][userPerson.GetID()]["debt"] = userPerson.GetBalance();
			//tempVec = userPerson.getCheckedOutList();
			/*for (CheckOutData* x : tempVec)
			{
				userInfo["users"][userPerson.GetID()][x->contentCheckedOut.GetISBN()]["timeCheckedOut"] = (long long)x->timeCheckedOut;
				userInfo["users"][userPerson.GetID()][x->contentCheckedOut.GetISBN()]["overTime"] = x->overTime;
			
				//edit for book or bundle
			}
	*/	}
	}
	ofstream fileOut;
	fileOut.open("userInfo.json");
	
	if (fileOut.is_open())
	{
		fileOut << userInfo;
	}
	fileOut.close();
}
