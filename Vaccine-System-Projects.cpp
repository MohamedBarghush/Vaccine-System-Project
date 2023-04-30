#include <iostream>
#include "mainManager.h"

using namespace std;

int main()
{
	MainManager mainManager;
	mainManager.CreateEntry("Mohamed Gamal", 19, "ExtraZinc", false);
	mainManager.CreateEntry("Omar Ahmed", 19, "ExtraZinc", true);
	mainManager.SaveEntriesToFile("TestingCases.csv");
	mainManager.ShowAll();
	return 0;
}
