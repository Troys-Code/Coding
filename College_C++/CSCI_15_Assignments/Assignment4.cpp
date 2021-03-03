#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>
#include <fstream>

using namespace std;

struct information
{
    string ID;
    string LastName;
    string FirstName;
    float Hours;
    float Payrate;
    float Taxrate;
};

void HitAnyKey();
void calculations(information[], float &, float &, float &, int);
void displayall(information [], float, float, float, int);
void transfer(information []);
int DataSize();

int main()
{
    char again = 'y';
    int option;
    int index;

    float Grosspay, TaxesWithheld, Netpay;
    Grosspay = TaxesWithheld = Netpay = 0;

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);


        while(again == 'y')
        {
            //for for loops.
            int width = DataSize();
            //int width = 100;
            information Employees[width];

            transfer(Employees);

            do
            {
                cout << "\n\tMenu:"
                     << "\n\n\t1 - Display All Employees"
                     << "\n\t2 - Find One Particular Employee"
                     << "\n\t3 - Add a New Employee"
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
                    cout << "\n\tOption 1 - Display All Employees";
                    cout << "\n\n\t" << width << " Total Employees:";
                    for(int n = 0; n < width; n++)
                    {
                        //calculations(Employees, gross, Taxes, Net);
                        calculations(Employees, Grosspay, TaxesWithheld, Netpay, n);
                        displayall(Employees, Grosspay, TaxesWithheld, Netpay, n);
                    }
                    break;
                }
                case 2:
                {
                    string temp;
                    system("cls");

                        cout << "\n\tOption 2 - Find One Employee";
                        cout << "\n\n\tThere are " << width << " Employees Stored in the Structure";
                        cout << "\n\n\tEnter the I.D. of the Employee You Would Like to Find: ";
                        cin.ignore();
                        cin.clear();
                        getline (cin,temp);
                        for(int n = 0; n < width; n++)
                        {
                            if(temp == Employees[n].ID)
                            {
                                calculations(Employees, Grosspay, TaxesWithheld, Netpay, n);
                                displayall(Employees, Grosspay, TaxesWithheld, Netpay, n);
                                HitAnyKey();
                                break;
                            }
                            if(temp != Employees[n].ID && n == width-1)
                            {
                                cout << "\n\t" << temp << " did not match with any of the Existing Employee IDs";
                                HitAnyKey();
                            }
                        }

                    break;
                }
                case 3:
                {
                    information newplayer;
                    system("cls");
                    cout << "\n\tOption 3 - Add a New Employee";

                    cout << "\n\t1 of 6 - Enter Employee's ID: ";
                    cin.ignore();
                    cin.clear();
                    getline(cin, newplayer.ID);

                    cout << "\n\t2 of 6 - Enter Employee's Last Name: ";
                    cin.clear();
                    getline(cin, newplayer.LastName);

                    cout << "\n\t3 of 6 - Enter Employee's First Name: ";
                    cin.clear();
                    getline(cin, newplayer.FirstName);

                    cout << "\n\t4 of 6 - Enter Employee's Amount of Hours Worked: ";
                    cin.clear();
                    cin >> newplayer.Hours;

                    cout << "\n\t5 of 6 - Enter Employee's Pay Rate: ";
                    cin.clear();
                    cin >> newplayer.Payrate;

                    cout << "\n\t6 of 6 - Enter Employee's Tax Rate (Ex: 0.05 = 5%): ";
                    cin.clear();
                    cin >> newplayer.Taxrate;

                    cout << "\n\n\tSaving Employee Information";
                    HitAnyKey();
                    ofstream outputFile;
                    outputFile.open("personnel1.dat" , ios::out|ios::app);

                    outputFile << "\n" << newplayer.ID << " " << newplayer.LastName << " " << newplayer.FirstName;
                    outputFile << " " << newplayer.Hours << " " << newplayer.Payrate << " " << newplayer.Taxrate;

                    outputFile.close();
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

void displayall(information workers[], float Grosspay, float TaxesWithheld, float Netpay, int index)
{
            cout << "\n\n\tEmployee #" << (index+1);
            cout << "\tEmployee ID: " << workers[index].ID;
            cout << "\n\tEmployee LAST NAME:  " << workers[index].LastName
                 << "\n\tEmployee FIRST NAME: " << workers[index].FirstName
                 << "\n\tHours Worked " << setw(17) << workers[index].Hours
                 << "\n\tEmployee Pay Rate:" << setw(7) << "$" << workers[index].Payrate
                 << "\n\tTax Rate of " << setw(17) << workers[index].Taxrate*100 << "%"
                 << "\n\tGross Pay:" << setw(15) << "$" << Grosspay
                 << "\n\tLess Taxes" << setw(15) << "$" << TaxesWithheld
                 << "\n\tNet Pay:" << setw(17) << "$"<< Netpay;
}

void transfer(information workers[])
{
    int count = 0;
    ifstream inputFile;
    inputFile.open("personnel1.dat");

    inputFile >> workers[count].ID >> workers[count].LastName >> workers[count].FirstName;
    inputFile >> workers[count].Hours >> workers[count].Payrate >> workers[count].Taxrate;

    while(!inputFile.eof())
    {
        count++;
        inputFile >> workers[count].ID >> workers[count].LastName >> workers[count].FirstName;
        inputFile >> workers[count].Hours >> workers[count].Payrate >> workers[count].Taxrate;
    }
    inputFile.close();
}

int DataSize()
{
    int count = 0;
    string word1, word2, word3;
    float num1, num2, num3;
    ifstream inputFile;
    inputFile.open("personnel1.dat");

    //inputFile >> word1 >> word2 >> word3;
    //inputFile >> num1 >> num2 >> num3;

    while(!inputFile.eof())
    {
        count++;
        inputFile >> word1 >> word2 >> word3;
        inputFile >> num1 >> num2 >> num3;
    }
    inputFile.close();

    //because it adds when it sees end of file marker for some reason.
    //count--;
    return count;

}



