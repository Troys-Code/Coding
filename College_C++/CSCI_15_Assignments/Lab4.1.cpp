#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

struct information
{
    string LastName;
    string FirstName;
    float Hours;
    float Payrate;
    float Taxrate;
};

void HitAnyKey();
void calculations(information[], float &, float &, float &, int);
void displayall(information [], float, float, float, int, int);

int main()
{
    char again = 'y';
    int option;
    int index;

    float Grosspay, TaxesWithheld, Netpay;
    Grosspay = TaxesWithheld = Netpay = 0;

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    //Since I put stuff in it, I don't need to put the size because the array already knows how big to make it.
    information Employees[] = {"De Bosse", "Ian D.", 34.5, 45.75, 0.05,
                                "Smithers III","Weylan K.S.", 40.1, 28.75, 0.04,
                                "Simpson", "Homer J.", 40, 23.44, 0.023,
                                "Haddington Smith", "Janet K.B.", 33.9, 35.75, 0.05,
                                "Jackson", "Sarah L.", 39.45, 17.88, 0.15,
                                "Kirk", "James Tiberius", 55.6, 89.65, 0.075,
                                "Griffin", "Peter R.", 25.6, 17.88, 0.04,
                                "Jones y Enrique", "Alias N.", 28.9, 37.88, 0.045
                                };
    //for for loops.
    int width = sizeof(Employees)/sizeof(information);


    while(again == 'y')
    {
        cout << "\n\tLoading the following records into the structure.\n";

        for(int n = 0; n < width; n++)
        {
            cout << "\n\t" << Employees[n].LastName << " " << Employees[n].FirstName
                 << " " << Employees[n].Hours << " " << Employees[n].Payrate
                 << " " << Employees[n].LastName << " " << Employees[n].Taxrate;
        }
        HitAnyKey();
        system("cls");

        cout << "\n\tDisplaying Employee Data Information and Calculations (Gross Pay, Taxes Withheld, Net Pay):";

        for(int n = 0; n < width; n++)
        {
            calculations(Employees, Grosspay, TaxesWithheld, Netpay, n);
            displayall(Employees, Grosspay, TaxesWithheld, Netpay, n, width);
        }

        HitAnyKey();
        system("cls");

        while(again == 'y')
        {
            do
            {
                cout << "\n\tMenu:"
                     << "\n\n\t1 - Change an Employee's Fields"
                     << "\n\t2 - Find One Employee"
                     << "\n\t3 - Display All Employees"
                     << "\n\t4 - Quit";

                cout << "\n\n\tEnter Option 1 to 4: ";
                cin >> option;
                cin.clear();
                system("cls");
            }while(option < 1 || option > 4);

            switch(option)
            {
                case 1:
                {
                    do
                    {
                        cout << "\n\tOption 1 - Change an Employee's Fields";
                        cout << "\n\tThere are " << width << " Employees Stored in the Structure";
                        cout << "\n\tEnter an Index from 0 to " << width-1 << ": ";
                        cin >> index;
                        system("cls");
                    }while(index < 0 || index > width-1);

                do{
                    int option2;
                    system("cls");
                    do
                    {
                        cout << "\n\tEnter An Option to Change in Index # " << index;
                        cout << "\n\n\t1 - Change Employee Last Name";
                        cout << "\n\t2 - Change Employee First Name";
                        cout << "\n\t3 - Change Employee Hours Worked";
                        cout << "\n\t4 - Change Employee Pay Per Hour";
                        cout << "\n\t5 - Change Employee Tax Rate ";
                        cout << "\n\t6 - QUIT Changes";
                        cout << "\n\n\tOption: ";
                        cin >> option2;
                        cin.ignore();
                        cin.clear();
                        system("cls");
                    }while(option2 < 1 || option2 > 6);

                    switch(option2)
                    {
                    case 1:
                        {
                            cout << "\n\tOption 1";
                            cout << "\n\tOriginal Last Name is " << Employees[index].LastName;
                            cout << "\n\tEnter New Employee Last Name: ";
                            //cin >> Employees[index].LastName;
                            getline(cin, Employees[index].LastName);
                            //cin.ignore();
                            cin.clear();
                            cout << "\n\tNew Last Name is " << Employees[index].LastName;
                            HitAnyKey();
                            break;
                        }
                    case 2:
                        {
                            cout << "\n\tOption 2";
                            cout << "\n\tOriginal First Name is " << Employees[index].FirstName;
                            cout << "\n\tEnter New Employee First Name: ";
                            //cin >> Employees[index].FirstName;
                            getline(cin, Employees[index].FirstName);
                            //cin.ignore();
                            cin.clear();
                            cout << "\n\tNew First Name is " << Employees[index].FirstName;
                            HitAnyKey();
                            break;
                        }
                    case 3:
                        {
                            cout << "\n\tOption 3";
                            cout << "\n\tOriginal Hours is " << Employees[index].Hours;
                            cout << "\n\tEnter New Employee Hours Worked: ";
                            cin >> Employees[index].Hours;
                            cout << "\n\tNew Hours is " << Employees[index].Hours;
                            HitAnyKey();
                            break;
                        }
                    case 4:
                        {
                            cout << "\n\tOption 4";
                            cout << "\n\tOriginal Pay Rate is " << Employees[index].Payrate;
                            cout << "\n\tEnter New Employee Pay Per Hour (Ex: 55 = $55.00): ";
                            cin >> Employees[index].Payrate;
                            cout << "\n\tNew Pay Rate is " << Employees[index].Payrate;
                            HitAnyKey();
                            break;
                        }
                    case 5:
                        {
                            cout << "\n\tOption 5";
                            cout << "\n\tOriginal Tax Rate is " << Employees[index].Taxrate;
                            cout << "\n\tEnter New Employee Tax Rate(Ex: 0.04 = 4.0%): ";
                            cin >> Employees[index].Taxrate;
                            cout << "\n\tNew Tax Rate is " << Employees[index].Taxrate;
                            cout << "\n\tHit Any Key To Continue...";
                            getch();
                            break;
                        }
                    case 6:
                        {
                            cout << "\n\tQuitting";
                            HitAnyKey();
                            again = 'n';
                            break;
                        }
                    }
                }while(again == 'y');
                    break;
                }
                case 2:
                {
                    do
                    {
                        cout << "\n\tOption 2 - Find One Employee";
                        cout << "\n\tThere are " << width << " Employees Stored in the Structure";
                        cout << "\n\tEnter an Index from 0 to " << width-1 << ": ";
                        cin >> index;
                        system("cls");
                    }while(index < 0 || index > width-1);

                    calculations(Employees, Grosspay, TaxesWithheld, Netpay, index);
                    displayall(Employees, Grosspay, TaxesWithheld, Netpay, index, width);
                    HitAnyKey();
                    break;
                }
                case 3:
                {
                    cout << "\n\tOption 3 - Display All Employees";
                    //displayall(Employees, Grosspay, TaxesWithheld, Netpay);
                    for(int n = 0; n < width; n++)
                    {
                        //calculations(Employees, gross, Taxes, Net);
                        calculations(Employees, Grosspay, TaxesWithheld, Netpay, n);
                        displayall(Employees, Grosspay, TaxesWithheld, Netpay, n, width);
                    }
                    break;
                }
                case 4:
                {
                    cout << "\n\tOption 4 - Quitting";
                    HitAnyKey();
                    again = 'n';
                    break;
                }
            }

            if(option !=4)
            {
                cout << "\n\n\tGo back to Original Menu? (y or n):\n\t";
                cin >> again;
                again = tolower(again);
                system("cls");
            }
        }

        cout << "\n\n\tRun this Program Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");
    }
}

void calculations(information workers[], float &grosspay, float &taxeswithheld, float &netpay, int count)
{
    grosspay = (workers[count].Hours * workers[count].Payrate);
    taxeswithheld = (grosspay * workers[count].Taxrate);
    netpay = grosspay - taxeswithheld;
}

void HitAnyKey()
{
    cout << "\n\n\tHit Any Key to Continue...";
    getch();
}

void displayall(information workers[], float Grosspay, float TaxesWithheld, float Netpay, int index, int width)
{
            cout << "\n\n\tEmployee #" << (index+1) << " of " << width;
            cout << "\n\tEmployee LAST NAME: " << workers[index].LastName
                 << "\n\tEmployee FIRST NAME: " << workers[index].FirstName
                 << "\n\t" << workers[index].Hours << " Hours Worked @ $" << workers[index].Payrate << " = $" << Grosspay
                 << "\n\tTax Rate of " << workers[index].Taxrate*100 << "%\t\t$" << TaxesWithheld
                 << "\n\tEmployee Gross Pay:\t\t$" << Netpay;
}



