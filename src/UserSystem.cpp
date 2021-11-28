#include "../header/UserSystem.hpp"
#include "../header/Person.hpp"
#include "../header/LoginSystem.hpp"
#include <fstream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <../header/CheckOutData.hpp>
#include <ctime>

using namespace std;

UserSystem::UserSystem(unordered_map<int, Person*> users, Person *nowPerson,)
{
	//import users from a file to populate the array
	ifstream people_file("userInfo.json", ifstream::binary);
	Json::Reader reader;
	Json::Value root;
	reader.parse(people_file,root);
	
	for (auto const& id : root.getMemberNames())
	{
		int debt;
		vector<CheckOutData*> checkoutData;
		string fullName = root["users"][id]["name"];
		int ID = id;
		if (root["users"][id]["debt"] != NULL)
		{
			debt = root["users"][id]["debt"];
			for (int i = 2; i < root["users"][id].size(); ++i)//start at 2 because 0 and 1 are name and debt
			{//size param might be wrong
				time_t timeChecked = root["users"][id][i]["timeCheckedOut"];
				bool overT = root["users"][id][i]["overTime"];
				int ISBN = root["users"][id][i]["ISBN"];
				Content* newCont(GetContent(ISBN));
				CheckOutData* tempData;
				tempData->timeCheckedOut = timeChecked;
				tempData->contentCheckedOut = newCont;
				tempData->userCheckedOut = 				
//bundle or book
			}
		}		
	}	
}

UserSystem::~UserSystem()
{
	for (auto &x : users)
		delete x;
}

Person* UserSystem::SetCurrPerson(Person *dude, string password) {
	if (LoginVerify(dude->ID, password, users))
		return dude;
	else
		return nullptr;
}

void UserSystem::AddPerson(Person *dude) {
	this->users.insert({ dude->ID, dude });	
}

void UserSystem::SaveUserData()
{
	Json::Value userInfo;
	vector<CheckOutData*> tempVec;
	Json::Value vec(Json::arrayValue);
	for (const auto & [ID, userPerson] : users)
	{
		userInfo["users"][userPerson.GetID()]["name"] = userPerson.GetName();
		if (dynamic_cast<User*> (userPerson))
		{
			userInfo["users"][userPerson.GetID()]["debt"] = userPerson.GetBalance();
			tempVec = userPerson.getCheckedOutList();
			for (CheckOutData* x : tempVec)
			{
				userInfo["users"][userPerson.GetID()][x->contentCheckedOut.GetISBN()]["timeCheckedOut"] = string(x->timeCheckedOut);
				userInfo["users"][userPerson.GetID()][x->contentCheckedOut.GetISBN()]["overTime"] = string(x->overTime);
				userInfo["users"][userPerson.GetID()][x->contentCheckedOut.GetISBN()]["ISBN"] = x->contentCheckedOut.GetISBN();
				//edit for book or bundle
			}
		}
	}
	ofstream fileOut;
	fileOut.open("userInfo.json");
	Json::StyledWriter writer;
	if (fileOut.is_open())
	{
		fileOut << writer.write(userInfo);
	}
	fileOut.close();
}
