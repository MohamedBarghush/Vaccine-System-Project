#pragma once
#include <string>
#include <iostream>

using namespace std;

class User {
private:
    string fullName;
    int id;
    string password;
    string government;
    int age;
    char gender;
    bool vaccinated;
public:
    User(string fullName, int id, string password, string government, int age, char gender, bool vaccinated) {
        this->fullName = fullName;
        this->id = id;
        this->password = password;
        this->government = government;
        this->age = age;
        this->gender = gender;
        this->vaccinated = vaccinated;
    };

    void display();

    void edit(string fullName, string password, string government, int age, char gender, bool vaccinated);

    void deleteUser();
};