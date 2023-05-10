#pragma once
#include <string>
#include <iostream>
#include"MainManager.h"

using namespace std;

class User:MainManager {
public:
    Entry userEntry;
    User() {

    };
    User(Entry entry, unordered_map<int, Entry> a, queue<Entry> q) {
        this->userEntry = entry;
    };

//Inherited Functions From Main Manager
    void CreateUserEntry();
    void EditUserEntry(int id);
    void DeleteUserEntry(int id);
    /*Entry ShowEntry(int id) {};
    bool ShowVaccineStatue(int id) {};*/
};