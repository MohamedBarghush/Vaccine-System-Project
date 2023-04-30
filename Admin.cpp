#include "Admin.h"

void Admin::Delete(int ID)
{
	DeleteEntry(ID);
}

void Admin::DeleteAll()
{
	
}

void Admin::ViewAll()
{
    cout << "Entries:\n";
    for (auto& entry : entries) {
        cout << "\n" << "Name: " << entry.second.name << "\n"
            << "ID: " << entry.second.id << "\n"
            << "Government: " << entry.second.government << "\n"
            << "Age: " << entry.second.age << "\n"
            << "Gender: " << entry.second.gender << "\n"
            << "Vaccine Type: " << entry.second.vaccineType << "\n"
            << "Vaccinated First Dose: " << (entry.second.firstDose ? "Yes, on " + entry.second.firstDoseDate : "No") << "\n"
            << "Vaccinated Second Dose: " << (entry.second.secondDose ? "Yes, on " + entry.second.secondDoseDate : "No") << "\n\n";
    }
}

void Admin::ViewOne(int ID)
{
    ShowEntry(ID);
}

void Admin::ViewOrderedByAge()
{

}

void Admin::ViewWaitingList()
{
    cout << "Waiting list:\n";
    queue<Entry> tempQueue = waitingList;
    int i = 1;
    while (!tempQueue.empty()) {
        Entry entry = tempQueue.front();
        cout << "\n" << i << ". Name: " << entry.name << "\n"
            << "ID: " << entry.id << "\n"
            << "Government: " << entry.government << "\n"
            << "Age: " << entry.age << "\n"
            << "Gender: " << entry.gender << "\n"
            << "Vaccine Type: " << entry.vaccineType << "\n"
            << "Vaccinated First Dose: " << (entry.firstDose ? "Yes, on " + entry.firstDoseDate : "No") << "\n"
            << "Vaccinated Second Dose: " << (entry.secondDose ? "Yes, on " + entry.secondDoseDate : "No") << "\n\n";
        tempQueue.pop();
        i++;
    }
    tempQueue.~queue();
}

void Admin::ViewDoses()
{

}

float Admin::ViewStatistics()
{
    int temp = 0;
    int males = 0;
    int females = 0;
    char input;
    cout << "Type F To see the The Amount of People Who Recieved The first Dose only Or Type B to see the Amount of People Who Recieved Both Doses Or Type G To See the Amount of Males and Females on The System" << endl;
    cin >> input;
    if (input == 'F' || input == 'f')
    {
        
        queue<Entry> tempList = waitingList;
        while (!tempList.empty()) {
            if (tempList.front().firstDose == true)
            {
                temp++;
            }
            tempList.pop();
        }
        tempList.~queue();
        return (temp / entries.size());
    }
    else if (input == 'B' || input == 'b')
    {
        for (pair<int, Entry> entry : entries) {
            if (entry.second.firstDose == true && entry.second.secondDose == true)
            {
                temp++;
            }
        }
        return (temp / entries.size());
    }
    else if (input == 'G' || input == 'g')
    {
        for (pair<int, Entry> entry : entries) {
            if (entry.second.age == 'M' || entry.second.age == 'm')
            {
                males++;
            }
        }
        queue<Entry> tempList = waitingList;
        while (!tempList.empty()) {
            if (tempList.front().age == 'M' || tempList.front().age == 'm')
            {
                males++;
            }
            tempList.pop();
        }
        tempList.~queue();
        return (males / entries.size());
        for (pair<int, Entry> entry : entries) {
            if (entry.second.age == 'F' || entry.second.age == 'f')
            {
                females++;
            }
        }
        queue<Entry> tempList = waitingList;
        while (!tempList.empty()) {
            if (tempList.front().age == 'F' || tempList.front().age == 'f')
            {
                females++;
            }
            tempList.pop();
        }
        tempList.~queue();
        return (females / entries.size());
    }

}