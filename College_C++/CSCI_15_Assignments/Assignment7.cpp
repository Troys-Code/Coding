#include <stdlib.h>
#include <conio.h> // used for getch();
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

#include "Employees.h"

using namespace std;

int main()
{
    char again = 'y';
    int option, choice;
    int width = 10;

    //Employee Properties
    string ID, status;
    float payrate, taxrate, hours;

    Hourly Workers[width];
    Salaried Managers[width];
    Contractor Plumber[width];

    Employee *worker = &Workers[0];
    Employee *manager = &Managers[0];
    Employee *contractor = &Plumber[0];

    Workers[0].Initialize("AS101", 32.34, 28.50, 0.055, "Hourly");
    Workers[1].Initialize("GH199", 44.5, 39.22, 0.04, "Hourly");
    Workers[2].Initialize("UY189", 47.22, 45.60, 0.016, "Hourly");

    Managers[0].Initialize("VE320", 45750.34, 0.07, "Salaried");
    Managers[1].Initialize("BR003", 65740.88, 0.065, "Salaried");
    Managers[2].Initialize("AA891", 50900.71, 0.12, "Salaried");

    Plumber[0].Initialize("BV111", 55473.56, "Contractor");
    Plumber[1].Initialize("NB290", 65540.87, "Contractor");
    Plumber[2].Initialize("VC100", 45679.25, "Contractor");

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    while(again == 'y')
    {
        do
        {
            Menu();
            cin >> option;
            system("cls");

        }while(option < 1 or option > 10);

        switch(option)
        {
            case 1:
            {
                do
                {
                    cout << "\n\t1 - Enter Data for Hourly Employees";
                    cout << "\n\n\tEnter and Index #0 - " << width-1 << ": ";
                    cin >> choice;
                    system("cls");
                }while(choice < 0 || choice > width-1);

                while(again == 'y')
                {
                    worker = &Workers[choice];
                    worker -> setovertime();
                    worker -> calculatepay();
                    worker -> Display(choice);
                    do
                    {
                        cout << "\n\n\t1 - Change Hourly ID"
                             << "\n\t2 - Change Hours"
                             << "\n\t3 - Change Pay Rate"
                             << "\n\t4 - Change Tax Rate"
                             << "\n\t5 - Change Hourly Status"
                             << "\n\t6 - Change All Hourly Properties"
                             << "\n\t7 - Quit Changes";
                        cout << "\n\n\tEnter an Option: ";
                        cin >> option;
                        cin.clear();
                        cin.ignore();
                        system("cls");
                    }while(option < 1 || option > 7);

                    switch(option)
                    {
                        case 6:
                            cout << "\n\tChanging All Hourly Properties\n\t";
                        case 1:
                        {
                            cout << "\n\t1 - Change Hourly ID";
                            cout << "\n\n\tEnter New ID: ";
                            getline(cin, ID);
                            cin.clear();
                            worker -> SetID(ID);
                            if(option != 6)
                            {
                                break;
                            }
                        }
                        case 2:
                        {
                            cout << "\n\t2 - Change Hours";
                            cout << "\n\n\tEnter new Hours: ";
                            cin >> hours;
                            worker -> SetHours(hours);
                            if(option != 6)
                            {
                                break;
                            }
                        }
                        case 3:
                        {
                            cout << "\n\t3 - Change Hourly Pay Rate";
                            cout << "\n\n\tEnter new Hourly Payrate: ";
                            cin >> payrate;
                            worker -> SetPay(payrate);
                            if(option != 6)
                            {
                                break;
                            }
                        }
                        case 4:
                        {
                            cout << "\n\t4 - Change Hourly Tax Rate";
                            cout << "\n\n\tEnter new Hourly Tax Rate (Ex: 0.05 = 5.00%): ";
                            cin >> taxrate;
                            worker -> SetTaxRate(taxrate);
                            if(option != 6)
                            {
                                break;
                            }
                        }
                        case 5:
                        {
                          cout << "\n\t5 - Change Status";
                            cout << "\n\n\tEnter new Hourly Status: ";
                            cin.ignore();
                            cin.clear();
                            getline(cin,status);
                            worker -> SetStatus(status);
                            if(option == 6)
                            {
                                worker -> Display(choice);
                            }
                            break;
                        }
                        case 7:
                        {
                            cout << "\n\tOption 7:"
                                 << "\n\tQuitting Changes...";
                            again = 'n';
                            break;
                        }
                    }
                    if(option != 7)
                    {
                        system("cls");
                    }
                }
                again = 'y';
                break;
            }
            case 2:
            {
                do
                {
                    cout << "\n\t1 - Enter Data for Salaried Employees";
                    cout << "\n\n\tEnter and Index #0 - " << width-1 << ": ";
                    cin >> choice;
                    system("cls");
                }while(choice < 0 || choice > width-1);

                while(again == 'y')
                {
                    manager = &Managers[choice];
                    manager -> calculatepay();
                    manager -> Display(choice);
                    do
                    {
                        cout << "\n\n\t1 - Change Salaried ID"
                             << "\n\t2 - Change Annual Salary"
                             << "\n\t3 - Change Tax Rate"
                             << "\n\t4 - Change Hourly Status"
                             << "\n\t5 - Change All Salaried Properties"
                             << "\n\t6 - Quit Changes";
                        cout << "\n\n\tEnter an Option: ";
                        cin >> option;
                        cin.clear();
                        cin.ignore();
                        system("cls");
                    }while(option < 1 || option > 6);

                    switch(option)
                    {
                        case 5:
                            cout << "\n\tChanging All Salaried Properties\n\t";
                        case 1:
                        {
                            cout << "\n\t1 - Change Salaried ID";
                            cout << "\n\n\tEnter New ID: ";
                            getline(cin, ID);
                            cin.clear();
                            manager -> SetID(ID);
                            if(option != 5)
                            {
                                break;
                            }
                        }
                        case 2:
                        {
                            cout << "\n\t2 - Change Annual Salary";
                            cout << "\n\n\tEnter new Annual Salary: ";
                            cin >> payrate;
                            manager -> SetPay(payrate);
                            if(option != 5)
                            {
                                break;
                            }
                        }
                        case 3:
                        {
                            cout << "\n\t3 - Change Salaried Tax Rate";
                            cout << "\n\n\tEnter new Salaried Tax Rate (Ex: 0.05 = 5.00%): ";
                            cin >> taxrate;
                            manager -> SetTaxRate(taxrate);
                            if(option != 5)
                            {
                                break;
                            }
                        }
                        case 4:
                        {
                            cout << "\n\t4 - Change Status";
                            cout << "\n\n\tEnter new Salaried Status: ";
                            cin.ignore();
                            cin.clear();
                            getline(cin,status);
                            manager -> SetStatus(status);
                            if(option == 5)
                            {
                                manager -> Display(choice);
                            }
                            break;
                        }
                        case 6:
                        {
                            cout << "\n\tOption 6:"
                                 << "\n\tQuitting Changes...";
                            again = 'n';
                            break;
                        }
                    }
                    if(option != 6)
                    {
                        system("cls");
                    }
                }
                again = 'y';
                break;
            }
            case 3:
            {
                do
                {
                    cout << "\n\t3 - Enter Data for Contractor Personnel";
                    cout << "\n\n\tEnter and Index #0 - " << width-1 << ": ";
                    cin >> choice;
                    system("cls");
                }while(choice < 0 || choice > width-1);

                while(again == 'y')
                {
                    contractor = &Plumber[choice];
                    contractor -> calculatepay();
                    contractor -> Display(choice);
                    do
                    {
                        cout << "\n\n\t1 - Change Contractor ID"
                             << "\n\t2 - Change Contractor Fee"
                             << "\n\t3 - Change Contractor Status"
                             << "\n\t4 - Change All Salaried Properties"
                             << "\n\t5 - Quit Changes";
                        cout << "\n\n\tEnter an Option: ";
                        cin >> option;
                        cin.clear();
                        cin.ignore();
                        system("cls");
                    }while(option < 1 || option > 5);

                    switch(option)
                    {
                        case 4:
                            cout << "\n\tChanging All Contractor Properties\n\t";
                        case 1:
                        {
                            cout << "\n\t1 - Change Contractor ID";
                            cout << "\n\n\tEnter New ID: ";
                            getline(cin, ID);
                            cin.clear();
                            contractor -> SetID(ID);
                            if(option != 4)
                            {
                                break;
                            }
                        }
                        case 2:
                        {
                            cout << "\n\t2 - Change Contractor Fee";
                            cout << "\n\n\tEnter new Contractor Fee: ";
                            cin >> payrate;
                            contractor -> SetPay(payrate);
                            if(option != 4)
                            {
                                break;
                            }
                        }
                        case 3:
                        {
                            cout << "\n\t3 - Change Status";
                            cout << "\n\n\tEnter new Hourly Status: ";
                            cin.ignore();
                            cin.clear();
                            getline(cin,status);
                            contractor -> SetStatus(status);
                            if(option == 4)
                            {
                                contractor -> Display(choice);
                            }
                            break;
                        }
                        case 5:
                        {
                            cout << "\n\tOption 5:"
                                 << "\n\tQuitting Changes...";
                            again = 'n';
                            break;
                        }
                    }
                    if(option != 5)
                    {
                        system("cls");
                    }
                }
                again = 'y';
                break;
            }
            case 4:
            {
                for(int n = 0; n < width; n++)
                {
                    worker = &Workers[n];
                    worker -> setovertime();
                    worker -> calculatepay();
                    worker -> Display(n);
                }
                break;
            }
            case 5:
            {
                for(int n = 0; n < width; n++)
                {
                    manager = &Managers[n];
                    manager -> calculatepay();
                    manager -> Display(n);
                }
                break;
            }
            case 6:
            {
                for(int n = 0; n < width; n++)
                {
                    contractor = &Plumber[n];
                    contractor -> calculatepay();
                    contractor -> Display(n);
                }
                break;
            }
            case 7:
            {
                cout << "\n\t7 - Terminate an Hourly Employee - set Employee Status to \"Hourly - Terminated\"";
                cout << "\n\n\tEnter an Index to Terminate (0-" << width-1 << "): ";
                cin >> choice;
                cout << "\n\n\tTerminating Index #" << choice;
                worker = &Workers[choice];
                worker -> setovertime();
                worker -> calculatepay();
                worker -> terminate();
                worker -> Display(choice);
                break;
            }
            case 8:
            {
                cout << "\n\t8 - Terminate a Salaried Employee - set Employee Status to \"Salaried - Terminated\"";
                cout << "\n\n\tEnter an Index to Terminate (0-" << width-1 << "): ";
                cin >> choice;
                cout << "\n\n\tTerminating Index #" << choice;
                manager = &Managers[choice];
                manager -> calculatepay();
                manager -> terminate();
                manager -> Display(choice);
                break;
            }
            case 9:
            {
                cout << "\n\t9 - Terminate a Contractor - set Employee Status to \"Contract Ended\"";
                cout << "\n\n\tEnter an Index to Terminate (0-" << width-1 << "): ";
                cin >> choice;
                cout << "\n\n\tTerminating Index #" << choice;
                contractor = &Plumber[choice];
                contractor -> calculatepay();
                contractor -> terminate();
                contractor -> Display(choice);
                break;
            }
            case 10:
            {
                cout << "\n\tOption 10:"
                << "\n\tQuitting...";
                again = 'n';
                break;
            }
        }

        cout << "\n\n\tHit Any Key to Continue...";
        getch();
        system("cls");

    }
}
