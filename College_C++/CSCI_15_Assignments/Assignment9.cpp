#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>
#include <vector> //must include to use vector
#include <algorithm> //used for vector sorts
#include <fstream>//ifstream/ofstream

using namespace std;

class record
{
    public:
    string ID;
    string lastName;
    string firstName;
//    char ID [5];
//    char lastName[20];
//    char firstName[30];
    float hours;
    float payrate;
    float income_taxrate;
    int dependents;

    public:
    void Display(int n)
    {
        cout << "\n\n\tIndex # " << n;
        cout << "\n\tID: " << ID
             << "\n\tLast Name:  " << lastName
             << "\n\tFirst Name: " << firstName
             << "\n\tHours: " << hours
             << "\n\tPay Rate: $" << payrate << setw(15)
             << " Tax Rate: " << income_taxrate*100 << "%"
             << "\n\tDependants: " << dependents;
    }

};

void HitAnyKey()
{
    cout << "\n\n\tHit Any Key to Continue...";
    getch();
    system("cls");
}

int main()
{
    int option;
    int width = 0;
    vector <record> Employee;
    record temp;
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    ifstream InputFile;
    InputFile.open("personnel5.txt", ios::in);

    Employee.push_back(record());
    InputFile >> Employee[0].ID >> Employee[0].lastName >> Employee[0].firstName
              >> Employee[0].hours >> Employee[0].payrate >> Employee[0].income_taxrate
              >> Employee[0].dependents;

    while(!InputFile.eof())
    {
        width++;
        Employee.push_back(record());
        InputFile >> Employee[width].ID >> Employee[width].lastName >> Employee[width].firstName
              >> Employee[width].hours >> Employee[width].payrate >> Employee[width].income_taxrate
              >> Employee[width].dependents;
    }
    InputFile.close();
    //width = Employee.size();

    do
    {
        do
        {
            cout << "\n\tMenu:";
            cout << "\n\t1 - Display the Contents of the Vector"
                     << "\n\t2 - Find a Record Based on Employee ID"
                     << "\n\t3 - Sort the records based on Last Name"
                     << "\n\t4 - Delete a record based on Employee ID"
                     << "\n\t5 - Change one or more of the fields, search for the target record based on Employee ID"
                     << "\n\t6 - Add a new record to the vector"
                     << "\n\t7 - Quit";
            cout << "\n\tEnter an Option: ";
            cin >> option;
            cin.clear();
            cin.ignore();
            system("cls");
        }while(option < 1 || option > 7);

        switch(option)
        {
            case 1:
            {
                cout << "\n\t1 - Display the Contents of the Vector";
                for(int n = 0; n < width; n++)
                {
                   Employee[n].Display(n);
                }
                break;
            }
            case 2:
            {
                cout << "\n\t2 - Find a Record Based on Employee ID";
                cout << "\n\n\tEnter Employee ID: ";
                cin >> temp.ID;
                bool status = false;
                for(int n = 0; n < width; n++)
                {
                    if(Employee[n].ID == temp.ID)
                    {
                        Employee[n].Display(n);
                        status = true;
                    }
                }
                if(status == false)
                {
                    cout << "\n\tEmployee ID does not match...";
                }
                break;
            }
            case 3:
            {
                cout << "\n\t3 - Sort the records based on Last Name";
                vector <string> temporary;
                for(int n = 0; n < width; n++)
                {
                    temporary.push_back(Employee[n].lastName);

                }
                sort(temporary.begin(),temporary.end());
                for(int n = 0; n < width; n++)
                {
                    for(int i = 0; i < width; i++)
                    {
                        if(Employee[i].lastName == temporary[n])
                        {
                            Employee[i].Display(n);
                            break;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                cout << "\n\t4 - Delete a record based on Employee ID";
                cout << "\n\tOnly Deletes the First Found...";
                cout << "\n\n\tEnter Employee ID: ";
                cin >> temp.ID;
                bool status = false;
                for(int n = 0; n < width; n++)
                {
                    if(Employee[n].ID == temp.ID)
                    {
                        Employee[n].Display(n);
                        cout << "\n\tDeleting...";
                        Employee.erase(Employee.begin() + n);
                        width--;
                        status = true;
                        break;
                    }
                }
                if(status == false)
                {
                    cout << "\n\tEmployee ID does not match...";
                }
                break;
            }
            case 5:
            {
                cout << "\n\t5 - Change one or more of the fields, search for the target record based on Employee ID";
                cout << "\n\tOnly Changes the First Found...";
                cout << "\n\n\tEnter Employee ID to Find: ";
                cin >> temp.ID;
                bool status = false;
                for(int n = 0; n < width; n++)
                {
                    if(Employee[n].ID == temp.ID)
                    {
                        do
                        {
                            do
                            {
                                Employee[n].Display(n);
                                cout << "\n\n\tCHANGE: ";
                                cout << "\n\t1 - Employee ID"
                                     << "\n\t2 - Last Name"
                                     << "\n\t3 - First Name"
                                     << "\n\t4 - Hours"
                                     << "\n\t5 - Pay Rate"
                                     << "\n\t6 - Income Tax Rate"
                                     << "\n\t7 - Dependants"
                                     << "\n\t8 - Change All Properties"
                                     << "\n\t9 - Return to Main Menu";
                                cout << "\n\tEnter an Option: ";
                                cin >> option;
                                system("cls");
                            }while(option < 1 || option > 9);

                            switch(option)
                            {
                                case 8:
                                    cout << "\n\tChanging All Properties\n\t";
                                case 1:
                                {
                                    cout << "\n\tEnter Employee ID: ";
                                    cin >> Employee[n].ID;
                                    if(option != 8)
                                    {
                                        break;
                                    }
                                }
                                case 2:
                                {
                                    cout << "\n\tEnter Last Name: ";
                                    cin >> Employee[n].lastName;
                                    if(option != 8)
                                    {
                                        break;
                                    }
                                }
                                case 3:
                                {
                                    cout << "\n\tEnter First Name: ";
                                    cin >> Employee[n].firstName;
                                    if(option != 8)
                                    {
                                        break;
                                    }
                                }
                                case 4:
                                {
                                    cout << "\n\tEnter Hours: ";
                                    cin >> Employee[n].hours;
                                    if(option != 8)
                                    {
                                        break;
                                    }
                                }
                                case 5:
                                {
                                    cout << "\n\tEnter Pay Rate: $";
                                    cin >> Employee[n].payrate;
                                    if(option != 8)
                                    {
                                        break;
                                    }
                                }
                                case 6:
                                {
                                    cout << "\n\tEnter Income Tax Rate (Ex: 0.01 = 1.00%): ";
                                    cin >> Employee[n].income_taxrate;
                                    if(option != 8)
                                    {
                                        break;
                                    }
                                }
                                case 7:
                                {
                                    cout << "\n\tEnter Dependents: ";
                                    cin >> Employee[n].dependents;
                                    if(option != 8)
                                    {
                                        break;
                                    }
                                }
                            }

                        }while(option != 9);
                        cout << "\n\tReturning to Main Menu...";
                        status = true;
                        break;
                    }
                }
                if(status == false)
                {
                    cout << "\n\tEmployee ID does not match...";
                }
                break;
            }
            case 6:
            {
                do
                {
                    cout << "\n\t6 - Add a new record to the vector";
                    cout << "\n\tEnter an index to place after from Index #0 - " << width << ": ";
                    cin >> option;
                }while(option < 0 || option > width);
                Employee.insert(Employee.begin()+option, Employee[option]);
                cout << "\n\n\t(1 of 7) Enter New ID: ";
                cin >> Employee[option].ID;
                cout << "\n\t(2 of 7) Enter Last Name: ";
                cin >> Employee[option].lastName;
                cout << "\n\t(3 of 7) Enter First Name: ";
                cin >> Employee[option].firstName;
                cout << "\n\t(4 of 7) Enter Hours: ";
                cin >> Employee[option].hours;
                cout << "\n\t(5 of 7) Enter Pay Rate: $";
                cin >> Employee[option].payrate;
                cout << "\n\t(6 of 7) Enter Tax Rate (Ex: 0.01 = 1%): ";
                cin >> Employee[option].income_taxrate;
                cout << "\n\t(7 of 7) Enter Number of Dependants: ";
                cin >> Employee[option].dependents;

                Employee[option].Display(option);
                width++;
                break;
            }
        }

        if(option != 7)
        {
            HitAnyKey();
            system("cls");
        }
    }while(option != 7);

    cout << "\n\tQuitting";
    HitAnyKey();

    ofstream outputFile;
    outputFile.open("personnel5.txt", ios::out);

    for(int n = 0; n < width; n++)
    {
        outputFile  << Employee[n].ID << " " << Employee[n].lastName << " " << Employee[n].firstName
                    << " " << Employee[n].hours << " " << Employee[n].payrate << " " << Employee[n].income_taxrate
                    << " " << Employee[n].dependents;
        outputFile << "\n";

    }
    outputFile.close();

}
