#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include "mainManager.h"

using namespace std;

// Function to create a new entry and add it to the entries vector or waiting list
void MainManager::CreateEntry(string name, int id, string government, int age, char gender, string vaccineType, bool firstDose, string firstDate, bool secondDose, string secondDate) {
    Entry newEntry = { name, id, government, age, gender, vaccineType, firstDose, firstDate, secondDose, secondDate };
    if (firstDose && secondDose) {
        entries.insert({ id, newEntry });  // Add to entries vector if already vaccinated
    }
    else {
        waitingList.push(newEntry);  // Add to waiting list if not yet vaccinated
    }
}

// Function to edit an entry and add it to the waiting list if not fully vaccinated
bool MainManager::EditEntry(int id, Entry newEntry) {
    bool found = false;
    queue<Entry> queueCopy = waitingList;
    int index = 0;
    while (!queueCopy.empty())
    {
        Entry entry = queueCopy.front();
        if (entry.id == id) {
            found = true;
            break;
        }
        index += 1;
        queueCopy.pop();
    }
    queueCopy.~queue();
    stack<Entry> tempQue;
    if (found) {
        while (index > 0) {
            tempQue.push(waitingList.front());
            waitingList.pop();
            index -= 1;
        }
        if (!(newEntry.firstDose && newEntry.secondDose))
            waitingList.front() = newEntry;
        else {
            waitingList.pop();
            entries.insert({ id, newEntry });
        }
        while (!tempQue.empty()) {
            waitingList.push(tempQue.top());
            tempQue.pop();
        }
        return true;
    }
    tempQue.~stack();

    auto it = entries.find(id);
    if (it != entries.end()) {
        if ((newEntry.firstDose && newEntry.secondDose))
            it->second = newEntry;
        else {
            waitingList.push(newEntry);
            DeleteEntry(id);
        }
        return true;
    }
    else {
        return false;
    }
}

// Function to check the vaccination status of a given entry
bool MainManager::CheckVaccineStatus(int id) {
    for (pair<int, Entry> entry : entries) {
        if (entry.second.id == id) {
            return (entry.second.firstDose && entry.second.secondDose);
        }
    }
    return NULL;  // Return NULL if no entry is found with the given name
}

// Function to delete an entry from the entries vector or waiting list
void MainManager::DeleteEntry(int id) {
    if (entries.erase(id)) {
        cout << "Entry deleted successfully\n";
    }
    else {
        // Check if the entry is in the waiting list
        queue<Entry> temp;
        bool found = false;
        while (!waitingList.empty()) {
            Entry entry = waitingList.front();
            if (entry.id == id) {
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
        temp.~queue();
    }
}

// Function to show a certain entry
void MainManager::ShowEntry(int id) {
    auto it = entries.find(id);
    if (it != entries.end()) {
        cout << "\n" << "Entry: \nName: " << it->second.name << "\n"
            << "ID: " << it->second.id << "\n"
            << "Government: " << it->second.government << "\n"
            << "Age: " << it->second.age << "\n"
            << "Gender: " << it->second.gender << "\n"
            << "Vaccine Type: " << it->second.vaccineType << "\n"
            << "Vaccinated First Dose: " << (it->second.firstDose ? "Yes, on " + it->second.firstDoseDate : "No") << "\n"
            << "Vaccinated Second Dose: " << (it->second.secondDose ? "Yes, on " + it->second.secondDoseDate : "No") 
            << "\nWaiting List: " << "NO" << "\n\n";
        return;
    }

    queue<Entry> tempQueue = waitingList;
    while (!tempQueue.empty()) {
        if (tempQueue.front().id == id) {
            cout << "\n" << "Entry: \nName: " << tempQueue.front().name << "\n"
                << "ID: " << tempQueue.front().id << "\n"
                << "Government: " << tempQueue.front().government << "\n"
                << "Age: " << tempQueue.front().age << "\n"
                << "Gender: " << tempQueue.front().gender << "\n"
                << "Vaccine Type: " << tempQueue.front().vaccineType << "\n"
                << "Vaccinated First Dose: " << (tempQueue.front().firstDose ? "Yes, on " + tempQueue.front().firstDoseDate : "No") << "\n"
                << "Vaccinated Second Dose: " << (tempQueue.front().secondDose ? "Yes, on " + tempQueue.front().secondDoseDate : "No")
                << "\nWaiting List: " << "YES" << "\n\n";
            tempQueue.~queue();
            return;
        }
        else {
            tempQueue.pop();
        }
    }
    tempQueue.~queue();
}

// Function to show all entries and waiting list
void MainManager::ShowAll() {
    cout << "Entries:\n";
    for (auto& entry : entries) {
        cout << "\n" << "Name: " << entry.second.name << "\n"
            << "ID: " << entry.second.id << "\n"
            << "Government: " << entry.second.government << "\n"
            << "Age: " << entry.second.age << "\n"
            << "Gender: " << entry.second.gender << "\n"
            << "Vaccine Type: " << entry.second.vaccineType << "\n"
            << "Vaccinated First Dose: " << (entry.second.firstDose ? "Yes, on " + entry.second.firstDoseDate : "No") << "\n"
            << "Vaccinated Second Dose: " << (entry.second.secondDose ? "Yes, on "+entry.second.secondDoseDate : "No") << "\n\n";
    }
    cout << "Waiting list:\n";
    int i = 1;
    while (!waitingList.empty()) {
        Entry entry = waitingList.front();
        cout << "\n" << i << ". Name: " << entry.name << "\n"
            << "ID: " << entry.id << "\n"
            << "Government: " << entry.government << "\n"
            << "Age: " << entry.age << "\n"
            << "Gender: " << entry.gender << "\n"
            << "Vaccine Type: " << entry.vaccineType << "\n"
            << "Vaccinated First Dose: " << (entry.firstDose ? "Yes, on " + entry.firstDoseDate : "No") << "\n"
            << "Vaccinated Second Dose: " << (entry.secondDose ? "Yes, on " + entry.secondDoseDate : "No") << "\n\n";
        waitingList.pop();
        i++;
    }
}

// Function to write the entries and waiting list to a CSV file
void MainManager::SaveEntriesToFile(string filename) {
    ofstream file(filename);
    file << "Name,ID,Government,Age,Gender,Vaccine Type,First Dose,First Date,Second Dose,Second Date\n";  // Write the header row
    for (pair<int, Entry> entry : entries) {
        file << entry.second.name
            << "," << entry.second.id
            << "," << entry.second.government
            << "," << entry.second.age
            << "," << entry.second.gender
            << "," << entry.second.vaccineType
            << "," << (entry.second.firstDose ? "Yes" : "No")
            << "," << (entry.second.firstDose ? entry.second.firstDoseDate : "")
            << "," << (entry.second.secondDose ? "Yes" : "No")
            << "," << (entry.second.secondDose ? entry.second.secondDoseDate : "")
            << "\n";
    }
    queue<Entry> tempList = waitingList;
    while (!tempList.empty()) {
        Entry entry = tempList.front();
        file << entry.name
            << "," << entry.id
            << "," << entry.government
            << "," << entry.age
            << "," << entry.gender
            << "," << entry.vaccineType
            << "," << (entry.firstDose ? "Yes" : "No")
            << "," << (entry.firstDose ? entry.firstDoseDate : "")
            << "," << (entry.secondDose ? "Yes" : "No")
            << "," << (entry.secondDose ? entry.secondDoseDate : "")
            << "\n";
        tempList.pop();
    }
    tempList.~queue();
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
        string line, name, government, vaccineType, firstDoseStr, firstDateStr, secondDoseStr, secondDateStr;
        int id, age;
        char genderChar;
        getline(file, line);  // Skip the header row
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            ss >> id;
            getline(ss, government, ',');
            ss >> age;
            ss >> genderChar;
            getline(ss, vaccineType, ',');
            getline(ss, firstDoseStr, ',');
            getline(ss, firstDateStr, ',');
            getline(ss, secondDoseStr, ',');
            getline(ss, secondDateStr, ',');
            bool firstDose = (firstDoseStr == "Yes");
            bool secondDose = (secondDoseStr == "Yes");
            CreateEntry(name, id, government, age, genderChar, vaccineType, firstDose, firstDateStr, secondDose, secondDateStr);
        }
        file.close();
        cout << "Entries loaded from file: " << filename << "\n";
    }
    else {
        cout << "Error: Unable to open file: " << filename << "\n";
    }
}