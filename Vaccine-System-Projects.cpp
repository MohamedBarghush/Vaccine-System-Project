#include <iostream>
#include "mainManager.h"
#include "User.h"
#include "Admin.h"

using namespace std;

int main()
{
	MainManager mainManager;
	mainManager.LoadEntriesFromFile("TestingCases.csv");
	User user(mainManager);
	Admin admin(mainManager);

    while (true)
    {
        system("cls");
        cout << "Welcome To Our Vaccine Tracking System \n";
        cout << "If You Are Admin Write Admin if you are User Type User \n";
        cout << "Case Doesnt Mater:\n";
        string s;
        cin >> s;
        for (auto& c : s) {
            c = tolower(c);
        }
        while (s != "user" && s != "admin") {
               cout << "Invalid input. Please check the spelling: \n";
                 cin >> s;
            transform(s.begin(), s.end(), s.begin(), [](unsigned char c) 
            {
                return tolower(c);
            });
        }
        cout << "Right input :) \n";

        if (s == "admin")
        {
            cout << "Enter The Admin Password\n";
            string pass;
            cin >> pass;
            bool flag = true;
            int count = 3;
            while (!mainManager.Check_Admin(pass, admin.password))
            {
                cout << "The password is not correct try again\n";
                cout << "You have " << count << " more attemps\n";
                cin >> pass;
                count--;
                if (count == 3)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                return 0;
            }
            int choice;
            cout << "To View all Records Press 1:\n";
            cout << "To View specific Record Press 2:\n";
            cout << "To Delete all Records Press 3:\n";
            cout << "To Delete specific Record Press 4:\n";
            cout << "To View records filtered by the number of doses (one dose and two doses) Press 5:\n";
            cout << "To View records of vaccinated users ordered by the age of the user Press 6:\n";
            cout << "To View the record of the user that needs to be vaccinated from the waiting list Press 7:\n";
            cout << "To View Basic statistics Press 8:\n";
            cin >> choice;

            while (choice < 0 || choice > 8)
            {
                cout << "Invalid input \n";
                cout << "Enter Your Choice again \n";
                cin >> choice;
            }
            if (choice == 1)
            {
                admin.ViewAll();
            }
            else if (choice == 2)
            {
                cout << "Enter The Id of the Record to Show\n";
                int id; cin >> id;
                admin.ViewOne(id);
            }
            else if (choice == 3) {
                admin.DeleteAll();
            }
            else if (choice == 4) {
                cout << "Enter The Id of the Record to Delete \n";
                int id; cin >> id;
                admin.Delete(id);
            }
            else if (choice == 5) {
                admin.ViewDosesRecord();
            }
            else if (choice == 6) {
                admin.ViewOrderedByAge();
            }
            else if (choice == 7) {
                admin.ViewWaitingList();
            }
            else if (choice == 8) {
                cout << "The Statistics are:\n";
                admin.ViewStatistics();
            }
        }
        else if (s == "user")
        {
            int choice;
            cout << "To Create New Entry Press 1:\n";
            cout << "To Access Your entry press 2\n";
            cin >> choice;
            while (choice < 1 || choice > 2)
            {
                cout << "Invalid Choice\n";
                cout << "Enter Your Choice again\n";
                cin >> choice;
            }
            if (choice == 1)
            {
                user.CreateUserEntry();
            }
            else if (choice == 2)
            {
                cout << "Enter Your Id:\n";
                int id1; cin >> id1;
                while (!mainManager.CheckID(id1))
                {
                    cout << "This Id doesn't exist in our database\n";
                    cout << "Please enter The Correct Id\n";
                    cin >> id1;
                }
                user.userEntry = mainManager.GetEntry(id1);
                cout << "Enter Your Password :\n";
                string password;
                int count = 0;
                cin >> password;
                while (user.userEntry.password != password)
                {
                    if (count == 0)
                    {
                        cout << "You Have 3 Attemps\n";
                    }
                    cout << "The Password is not correct \n";
                    cout << "Please enter The Password Again\n";
                    count++;
                    cin >> password;
                }
                int choice2;
                cout << "To View Your Data Press 1:\n";
                cout << "To Edit Your Record Press 2:\n";
                cout << "To Delete Your Record Press 3:\n";
                cin >> choice2;
                while (choice2 < 1 || choice2>3)
                {
                    cout << "Invalid Choice\n";
                    cin >> choice;
                }
                if (choice2 == 1)
                {
                    user.ShowUserEntry(id1);
                }
                else if (choice2 == 2)
                {
                    user.EditUserEntry(id1);
                }
                else if (choice2 == 3)
                {
                    user.DeleteUserEntry(id1);
                }
            }
        }
        cout << "If You Want To Continue Press Y or y\n";
        cout << "Else press N or n\n";
        char ch; cin >> ch;
        while (ch != 'N' && ch != 'n' && ch != 'Y' && ch != 'y')
        {
            cout << "Invalid input Please enter it again\n";
            cin >> ch;
        }
        if (ch == 'N' || ch == 'n')
        {
            mainManager.SaveEntriesToFile("TestingCases.csv");
            break;
        }
    }
    
	return 0;
}
