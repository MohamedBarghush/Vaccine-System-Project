#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include "mainManager.h"

using namespace std;

// Function to create a new entry and add it to the entries vector or waiting list
void MainManager::CreateEntry(string name, int age, string vaccineType, bool vaccinated) {
    Entry newEntry = { name, age, vaccineType, vaccinated };
    if (vaccinated) {
        entries.insert({ name, newEntry });  // Add to entries vector if already vaccinated
    }
    else {
        waitingList.push(newEntry);  // Add to waiting list if not yet vaccinated
    }
}

// Function to check the vaccination status of a given entry
bool MainManager::CheckVaccineStatus(string name) {
    for (pair<string, Entry> entry : entries) {
        if (entry.second.name == name) {
            return entry.second.vaccinated;
        }
    }
    return false;  // Return false if no entry is found with the given name
}

// Function to delete an entry from the entries vector or waiting list
void MainManager::DeleteEntry(string name) {
    if (entries.erase(name)) {
        cout << "Entry deleted successfully\n";
    }
    else {
        // Check if the entry is in the waiting list
        queue<Entry> temp;
        bool found = false;
        while (!waitingList.empty()) {
            Entry entry = waitingList.front();
            if (entry.name == name) {
                found = true;
                break;
            }
            temp.push(entry);
            waitingList.pop();
        }
        while (!temp.empty()) {
            Entry entry = temp.front();
            waitingList.push(entry);
            temp.pop();
        }
        if (found) {
            cout << "Entry deleted successfully\n";
        }
        else {
            cout << "Error: Entry not found\n";
        }
    }
}

// Function to show all entries and waiting list
void MainManager::ShowAll() {
    cout << "Entries:\n";
    for (auto& entry : entries) {
        cout << "Name: " << entry.second.name << "\n"
            << "Age: " << entry.second.age << "\n"
            << "Vaccine Type: " << entry.second.vaccineType << "\n"
            << "Vaccinated: " << (entry.second.vaccinated ? "Yes" : "No") << "\n\n";
    }
    cout << "Waiting list:\n";
    int i = 1;
    while (!waitingList.empty()) {
        Entry entry = waitingList.front();
        cout << i << ". Name: " << entry.name << "\n"
            << "Age: " << entry.age << "\n"
            << "Vaccine Type: " << entry.vaccineType << "\n"
            << "Vaccinated: " << (entry.vaccinated ? "Yes" : "No") << "\n\n";
        waitingList.pop();
        i++;
    }
}

// Function to write the entries and waiting list to a CSV file
void MainManager::SaveEntriesToFile(string filename) {
    ofstream file(filename);
    file << "Name,Age,Vaccine Type,Vaccinated\n";  // Write the header row
    for (pair<string, Entry> entry : entries) {
        file << entry.second.name
            << "," << entry.second.age
            << "," << entry.second.vaccineType
            << "," << (entry.second.vaccinated ? "Yes" : "No")
            << "\n";
    }
    while (!waitingList.empty()) {
        Entry entry = waitingList.front();
        file << entry.name
            << "," << entry.age
            << "," << entry.vaccineType
            << "," << (entry.vaccinated ? "Yes" : "No")
            << "\n";
        waitingList.pop();
    }
    file.close();
    cout << "Entries saved to file: " << filename << "\n";
}

// Function to load entries and waiting list from a CSV file
void MainManager::LoadEntriesFromFile(string filename) {
    entries.clear();  // Clear existing entries
    while (!waitingList.empty()) {
        waitingList.pop();  // Clear existing waiting list
    }
    ifstream file(filename);
    if (file.is_open()) {
        string line, name, vaccineType, vaccinatedStr;
        int age;
        getline(file, line);  // Skip the header row
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            ss >> age;
            getline(ss, vaccineType, ',');
            getline(ss, vaccinatedStr, ',');
            bool vaccinated = (vaccinatedStr == "Yes");
            CreateEntry(name, age, vaccineType, vaccinated);
        }
        file.close();
        cout << "Entries loaded from file: " << filename << "\n";
    }
    else {
        cout << "Error: Unable to open file: " << filename << "\n";
    }
}