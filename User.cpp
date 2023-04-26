#include "user.h"

using namespace std;

void User::display() {
    cout << "Full Name: " << fullName << endl;
    cout << "ID: " << id << endl;
    cout << "Government: " << government << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Vaccinated: " << (vaccinated ? "Yes" : "No") << endl;
}
void User::edit(string fullName, string password, string government, int age, char gender, bool vaccinated) {
    this->fullName = fullName;
    this->password = password;
    this->government = government;
    this->age = age;
    this->gender = gender;
    this->vaccinated = vaccinated;
};
void deleteUser() {
    // code to delete the user's record
};