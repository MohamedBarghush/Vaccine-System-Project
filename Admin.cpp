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
}

void Admin::ViewDoses()
{
}

float Admin::ViewStatistics()
{
	return 0.0f;
}