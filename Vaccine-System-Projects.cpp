#include <iostream>
#include "mainManager.h"

using namespace std;

int main()
{
	MainManager mainManager;
	mainManager.CreateEntry("Mohamed Gamal", 2021170458, "Cairo", 19, 'M', "ExtraZinc", true, "21/4/2021", true, "21/6/2021");
	mainManager.CreateEntry("Omar Ahmed", 2021170459, "Cairo", 21, 'M', "ExtraZinc", true, "21/4/2021", false , "");
	mainManager.CreateEntry("Yousef Eslam", 2021170460, "Cairo", 22, 'M', "ExtraZinc", true, "", false, "21/6/2021");
	//mainManager.CreateEntry("Samira Adel", 2021170461, "Cairo", 23, 'F', "ExtraZinc", false, "", false, "");
	//Entry newEntry = { "Mohamed Gamal", 2021170458, "Cairo", 20, 'M', "ExtraZinc", false, "21/4/2021", true, "21/6/2021" };
	//mainManager.EditEntry(newEntry.id, newEntry);
	mainManager.SaveEntriesToFile("TestingCases.csv");
	//mainManager.ShowEntry(2021170459);
 //   //mainManager.ShowAll();
	//for (unordered_map<int, Entry>::iterator i = mainManager.entries.begin(); i != mainManager.entries.end(); i++)
	//	cout << i->second.name << i->second.age;
	mainManager.MainMenu();
	return 0;
}
