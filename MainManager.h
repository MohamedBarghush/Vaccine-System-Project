#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// Define Entry struct to hold information about each entry
struct Entry {
public:
    string name;
    int age;
    string vaccineType;
    bool vaccinated;
 /*
    int id;
    string password;
    string government;
    char gender;
    */
};

class MainManager {
private:
    unordered_map<string, Entry> entries; // Map to store the entries
    queue<Entry> waitingList; // Queue to store the entries waiting for vaccination

public:
    // Function to create a new entry and add it to the entries vector or waiting list
    void CreateEntry(string name, int age, string vaccineType, bool vaccinated);
    // Function to check the vaccination status of a given entry
    bool CheckVaccineStatus(string name);
    // Function to delete an entry from the entries vector or waiting list
    void DeleteEntry(string name);
    // Function to show all entries and waiting list
    void ShowAll();
    // Function to write the entries and waiting list to a CSV file
    void SaveEntriesToFile(string filename);
    // Function to load entries and waiting list from a CSV file
    void LoadEntriesFromFile(string filename);
};
