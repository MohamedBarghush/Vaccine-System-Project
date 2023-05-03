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
    int id;
    string government;
    int age;
    char gender;
    string vaccineType;
    bool firstDose;
    string firstDoseDate;
    bool secondDose;
    string secondDoseDate;
};

class MainManager {
protected:
    unordered_map<int, Entry> entries; // Map to store the entries
    queue<Entry> waitingList; // Queue to store the entries waiting for vaccination

public:
    // Function to create a new entry and add it to the entries vector or waiting list
    void CreateEntry(string name, int id, string government, int age, char gender, string vaccineType, bool firstDose, string firstDate, bool secondDose, string secondDate);
    // Function to edit an entry and add it to the waiting list if not fully vaccinated
    bool EditEntry(int id, Entry newEntry);
    // Function to check the vaccination status of a given entry
    bool CheckVaccineStatus(int id);
    // Function to delete an entry from the entries vector or waiting list
    void DeleteEntry(int id);
    void Delete_All();
    // Function to show a certain entry
    void ShowEntry(int id);
    // Function to show all entries and waiting list
    void ShowAll();
    // Function to write the entries and waiting list to a CSV file
    void SaveEntriesToFile(string filename);
    // Function to load entries and waiting list from a CSV file
    void LoadEntriesFromFile(string filename);
    //A function that 

    // Main Menu Functions
    void MainMenu();
    void Start();
    bool Check_Admin(string s);
};
