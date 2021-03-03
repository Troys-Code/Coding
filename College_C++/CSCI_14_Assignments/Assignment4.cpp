#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number srand function.
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>
#include <fstream>

using namespace std;

void header();

int main( )
{
    string lastname, firstname, workerID;
    float hours, payrate, taxrate, grosspay, taxes, netpay;

    char again = 'y';
    int input;

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    while(again == 'y')
    {
        int count = 0;
        header();

        cin >> input;

        switch(input)
        {
            case 1:
            {
                cout << "\n\tEnter Employee ID (Ex: AD2201) ";
                cin >> workerID;

                cout << "\n\tEnter Last Name ";
                cin >> lastname;

                cout << "\n\tEnter First Name ";
                cin >> firstname;

                cout << "\n\tEnter Hours Worked ";
                cin >> hours;

                cout << "\n\tEnter Payrate (Amount Paid Per Hour) ";
                cin >> payrate;

                cout << "\n\tEnter Employee Tax Rate ";
                cin >> taxrate;

            ofstream outputFile;
            outputFile.open("MyFile.dat", ios::out|ios::app);

            //can't transfer more than one variable in 1 output File at a time.
            outputFile << workerID << " " << lastname << " " << firstname;
            outputFile << " " << hours << " " << payrate << " " << taxrate;
            outputFile << "\n";
            outputFile.close();
            break;
            }

            case 2:
            {
                ifstream inputFile;
                inputFile.open("MyFile.dat");
                string word1, word2,word3;
                float num1, num2, num3;

                inputFile >> word1 >> word2 >> word3;
                inputFile >> num1 >> num2 >> num3;

                while(!inputFile.eof())
                {

            //calculations
            grosspay = num1 * num2;
            taxes = grosspay * num3;
            netpay = grosspay - taxes;

                    count++;
                    cout << "\n\t\tRecord #" << count;

                    cout << "\n\tWorker ID: " << word1;


                    cout << "\n\tLast Name: " << word2;


                    cout << "\n\tFirst Name: " << word3;


                    cout << "\n\tHours Worked: " << num1;
                    cout << "\tPay Per Hour: $" << num2;
                    cout << "\tGross Pay: $" << grosspay;
                    cout << "\n\tTaxes Paid: $" << taxes;
                    cout << "\tNet Pay: $" << netpay;
                    cout << "\n\tEmployee Tax Rate: " << num3*100 << "%\n";


                //closes while loop
                inputFile >> word1 >> word2 >> word3;
                inputFile >> num1 >> num2 >> num3;

                }
                inputFile.close();
            break;
            }
            case 3:
            {
            cout << "\n\tEnding Program. . .";
            again = 'n';
            break;
            }
            default:
            {
                cout << "\n\tYou have entered an invalid option. Please go back and enter a valid option";
                break;
            }

        }

    if (again == 'y')
    {
        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");
    }

    }
}

void header()
{
    cout << "\n\n\t\tEnter an option"
             << "\n\t1 - Write new records to the data file"
             << "\n\t2 - Display records from the data file to the screen"
             << "\n\t3 - QUIT"
             << "\n\n\tEnter Option: ";
}

