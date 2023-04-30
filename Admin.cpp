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

void Admin::ViewDoses()
{

}

float Admin::ViewStatistics()
{
	return 0.0f;
}