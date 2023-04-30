#pragma once
#include <string>
#include <iostream>
#include"MainManager.h"

using namespace std;

class User:MainManager {
public:
    string fullName;
    int id;
    string password;
    string government;
    int age;
    char gender;
    bool vaccinated;
    User(string fullName, int id, string password, string government, int age, char gender, bool vaccinated) {
        this->fullName = fullName;
        this->id = id;
        this->password = password;
        this->government = government;
        this->age = age;
        this->gender = gender;
        this->vaccinated = vaccinated;
    };

//Inherited Functions From Main Manager
    void CreateEntry() {};
    bool EditEntry(int id) {};
    void DeleteEntry(int id) {};
    Entry ShowEntry(int id) {};
    bool ShowVaccineStatue(int id) {};
};