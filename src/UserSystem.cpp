#include "../header/UserSystem.hpp"
#include "../header/Person.hpp"
#include "../header/LoginSystem.hpp"
#include <fstream>
#include "../header/CheckOutData.hpp"
#include <ctime>
#include "../header/json.hpp"

using json = nlohmann::json;

using namespace std;

Person* UserSystem::GetPerson(int ID)
{
	if (this->people.find(ID) !=this->people.end())
		return this->people[ID];
	else
		return nullptr;
}

UserSystem::UserSystem(string peopleInput, string checkOut, vector<CheckOutData*>& checkedOut, deque<CheckOutData*>& passedDue, LibrarySystem* set_library)
{
	//import users from a file to populate the array
	ifstream people_file(peopleInput);
	json readJson;
	json readCheckedOut;
	ifstream checkout(checkOut);
	checkout >> readCheckedOut;
	people_file >> readJson;
	unordered_map<int, Person*> userMap;
	for (auto it : readJson)
	{
		int debt;
		vector<CheckOutData*> checkoutData;
		int ID = it;
		string name = readJson["users"][ID]["name"];
		int hashPass = readJson["users"][ID]["hashPass"];
		if (readJson["users"][ID].find("debt") != readJson.end())
		{
			debt = readJson["users"][ID]["debt"];
			User* tempUser = new User(name, ID, set_library, hashPass);
			tempUser->PayBalance(-1*debt);
			for (auto book : checkedOut)
			{
				if (book->userCheckedOut->GetId() == ID)
				{
					checkoutData.push_back(book);
				}
			}
			for (auto book : passedDue)
			{
				if (book->userCheckedOut->GetId() == ID)
					checkoutData.push_back(book);
			}
			tempUser->SetCheckedOutData(checkoutData);
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
			Librarian* tempLibrarian = new Librarian(name, ID, set_library, hashPass);
			userMap[ID] = tempLibrarian;
		}
		
	}
	this->people = userMap;
	people_file.close();	
  checkout.close();
}
UserSystem::~UserSystem()
{
	for (auto &x : people)
  {
    if (dynamic_cast<User*>(x.second) != nullptr)
      delete dynamic_cast<User*>(x.second);
    else
      delete dynamic_cast<Librarian*>(x.second);
  }
		
}

//Person* UserSystem::SetCurrPerson(Person *dude, string password) {
//	if (LoginVerify(dude->ID, password, users))
//		return dude;
//	else
//		return nullptr;
//}

void UserSystem::AddPerson(Person *person) {
	this->people.insert({ person->GetId(), person });	
}

void UserSystem::SaveUserData(string userInfo)
{
	json userJson;
	
	vector<CheckOutData*> tempVec;
	for (pair<int, Person*> kv : people)
	{
		userJson["users"][kv.first]["hashpass"] = kv.second->GetHashedPassword();
		userJson["users"][kv.first]["name"] = kv.second->GetName();
		if (dynamic_cast<User*> (kv.second) != nullptr)
		{
			userJson["users"][kv.first]["debt"] = dynamic_cast<User*>(kv.second)->GetBalance();
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
	fileOut.open(userInfo);
	
	if (fileOut.is_open())
	{
		fileOut << userInfo;
	}
	fileOut.close();
}
