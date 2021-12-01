#include "../header/UserSystem.hpp"

using json = nlohmann::json;

using namespace std;

unordered_map<int, Person*>& UserSystem::GetMap() { return people; }

Person* UserSystem::GetPerson(int ID)
{
	if (this->people.find(ID) !=this->people.end())
		return this->people[ID];
	else
		return nullptr;
}

void UserSystem::AddCheckedOut(unordered_map<int, set<CheckOutData*>> checkedOut)
{
  for (auto & [id, person] : people)
  {
    if (dynamic_cast<User*>(person) != nullptr)
    {
      vector<CheckOutData*> checkoutData;
      for (auto book : checkedOut[id])
			  {
			  	checkoutData.push_back(book);
			  }
      dynamic_cast<User*>(person)->SetCheckedOutData(checkoutData);
    }
  }
}

UserSystem::UserSystem(string peopleInput, BookSystem* bs)
{
	//import users from a file to populate the array
	ifstream people_file;
  people_file.open(peopleInput);
	json readJson;
  if (people_file.is_open() == false)
    cout << "not open" << endl;
	// json readCheckedOut;
	// ifstream checkout(checkOut);
	// checkout >> readCheckedOut;
	people_file >> readJson;
	unordered_map<int, Person*> userMap;
	for (auto it : readJson)
	{  

		int debt;
		// set<CheckOutData*> checkoutData;

		int ID = it["id"];
		string name = it["name"];
		int hashPass = it["hashPass"];

		if (it.find("debt") != it.end())
		{
			debt = it["debt"];
			User* tempUser = new User(name, ID, bs, hashPass);

			tempUser->PayBalance(-1*debt);
			// for (auto book : checkedOut[ID])
			// {
			// 	checkoutData.insert(book);
			// }
			
			// dynamic_cast<User*>(tempUser)->SetCheckedOutData(checkoutData);

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
			Librarian* tempLibrarian = new Librarian(name, ID, bs, hashPass);
			userMap[ID] = tempLibrarian;
		}
		
	}
	this->people = userMap;
	people_file.close();	
  // checkout.close();
}

UserSystem::~UserSystem() {
	for (auto &x : people)
	{
    if (dynamic_cast<User*>(x.second)!=nullptr)
      delete dynamic_cast<User*>(x.second);
    else
      delete dynamic_cast<Librarian*>(x.second);
  }	
}

void UserSystem::AddPerson(LoginSystem *logSys, Person *person) {
  logSys->AddPass(person->GetId(), person->GetHashedPassword());
	this->people.insert({ person->GetId(), person });	
}


void UserSystem::SaveUserData(string userInfo)
{
	json userJson;

	vector<CheckOutData*> tempVec;
  int i = 0;
	for (pair<int, Person*> kv : people)
	{
		userJson[i]["hashpass"] = kv.second->GetHashedPassword();
		userJson[i]["name"] = kv.second->GetName();
    userJson[i]["id"] = kv.second->GetId();
		if (dynamic_cast<User*> (kv.second) != nullptr)
		{
			userJson[i]["debt"] = dynamic_cast<User*>(kv.second)->GetBalance();
			//tempVec = userPerson.getCheckedOutList();
			/*for (CheckOutData* x : tempVec)
			{
				userInfo["users"][userPerson.GetID()][x->contentCheckedOut.GetISBN()]["timeCheckedOut"] = (long long)x->timeCheckedOut;
				userInfo["users"][userPerson.GetID()][x->contentCheckedOut.GetISBN()]["overTime"] = x->overTime;
			
				//edit for book or bundle
			}
	*/	}
    ++i;
	}
	ofstream fileOut;
	fileOut.open(userInfo);
	
	if (fileOut.is_open())
	{
		fileOut << userInfo;
	}
	fileOut.close();
}
