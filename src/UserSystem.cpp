#include "../header/UserSystem.hpp"
#include "../header/Person.hpp"
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


UserSystem::UserSystem(string peopleInput, BookSystem* bs)
{
	//import users from a file to populate the array
	ifstream people_file;
  people_file.open(peopleInput);
	json readJson;
  if (people_file.is_open() == false)
    cout << "not open" << endl;
	people_file >> readJson;
	unordered_map<int, Person*> userMap;
	for (auto it : readJson)
	{  
    // cout << "start";
    // cout << it;
    
    if (userMap.find(it["id"]) == userMap.end())
    {
      int i = 0;      
      int debt;      
      int ID = it["id"];     
      string name = it["name"];     
      int hashPass = it["hashpass"];      
      if (it.find("debt") != it.end())
      {        
        debt = it["debt"];      
        Person* tempUser = new User(name, ID, bs, hashPass);      

        dynamic_cast<User*>(tempUser)->PayBalance(-1*debt);      
        userMap[ID] = tempUser;     
      }
      else
      {      
        Person* tempLibrarian = new Librarian(name, ID, bs, hashPass);   
        userMap[ID] = tempLibrarian;    
      }
    }
	}    
	this->people = userMap;
	people_file.close();
}

UserSystem::~UserSystem() {
	for (pair<int, Person*> x : people)
	{
    // cout << x.second->GetName() << endl;

    delete x.second;
  }	
}

void UserSystem::AddPerson(LoginSystem *logSys, Person *person) {
  if (people.find(person->GetId()) != people.end()) {}
  else
  {
    logSys->AddPass(person->GetId(), person->GetHashedPassword());
    this->people.insert({ person->GetId(), person });	
  }
  
}

void UserSystem::SaveUserData(string userInfo)
{
	json userJson;
  int i = 0;
	for (pair<int, Person*> kv : people)
	{
		userJson[i]["hashpass"] = kv.second->GetHashedPassword();
		userJson[i]["name"] = kv.second->GetName();
    userJson[i]["id"] = kv.second->GetId();
		if (dynamic_cast<User*> (kv.second) != nullptr)
		{
			userJson[i]["debt"] = dynamic_cast<User*>(kv.second)->GetBalance();
		}
    ++i;
	}
	ofstream fileOut;
	fileOut.open(userInfo);
	
	if (fileOut.is_open())
	{
		fileOut << std::setw(3) << userJson;
	}
	fileOut.close();
}
