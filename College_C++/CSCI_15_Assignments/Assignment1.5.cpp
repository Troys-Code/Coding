#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

void header();
float absolute(float);

int main()
{
    int option;
    string lastname, firstname, workerID;
    //char lastname [30], firstname[30], workerID [10];
    float hours, searchhours, payrate, fedtaxrate, statetaxrate, grosspay, fedrate, staterate, netpay;

    char again = 'y';

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    while(again == 'y')
    {
        int count = 0, counter = 0;
        header();

        cout << "\n\n\tEnter Your Option: ";
        cin >> option;

        switch(option)
        {
            case 1:
                {
                    system("cls");
                    cout << "\n\tOption 1";
                    cout << "\n\n\t(1 of 7) Enter Employee ID (Ex: AD2201) ";
                    cin >> workerID;


                    cout << "\n\t(2 of 7) Enter Last Name ";
                    cin >> lastname;


                    cout << "\n\t(3 of 7) Enter First Name ";
                    cin >> firstname;


                    cout << "\n\t(4 of 7) Enter Hours Worked ";
                    cin >> hours;
                    hours = absolute(hours);

                cout << "\n\t(5 of 7) Enter Payrate (Amount Paid Per Hour) ";
                cin >> payrate;
                payrate = absolute(payrate);

                cout << "\n\t(6 of 7) Enter Federal Tax Rate (Ex: 0.01 = 1.00%) ";
                cin >> fedtaxrate;
                fedtaxrate = absolute(fedtaxrate);

                cout << "\n\t(7 of 7) Enter State Tax Rate (Ex: 0.01 = 1.00%) ";
                cin >> statetaxrate;
                statetaxrate = absolute(statetaxrate);

                ofstream outputFile;
                outputFile.open("personnel2.dat", ios::out|ios::app);

                outputFile << workerID << " " << lastname << " " << firstname;
                outputFile << " " << hours << " " << payrate << " " << fedtaxrate << " " << statetaxrate;
                outputFile << "\n";
                outputFile.close();
                    break;
                }
            case 2:
                {
                    system("cls");
                    cout << "\n\tOption 2\n";
                    ifstream inputFile;
                    inputFile.open("personnel2.dat");
                    //string word1[10], word2[10], word3[30];
                    string word1, word2, word3;
                    float num1, num2, num3, num4;

                    inputFile >> word1 >> word2 >> word3;
                    inputFile >> num1 >> num2 >> num3 >> num4;

                    while(!inputFile.eof())
                    {

                //calculations
                grosspay = num1 * num2;
                fedrate = num3 * grosspay;
                staterate = num4 * grosspay;
                netpay = grosspay - fedrate - staterate;

                        count++;
                        cout << "\n\t\tRecord #" << count;

                        cout << "\n\tEmployee ID: " << word1;

                        cout << "\n\tEmployee Name: " << word3 << " " << word2;


                        cout << "\n\tHours Worked: " << num1;
                        cout << "\tPay Per Hour: $" << num2;
                        cout << "\tGross Pay: $" << grosspay;
                        cout << "\n\tFederal Taxes: $" << fedrate;
                        cout << "\tState Taxes: $" << staterate;
                        cout << "\tNet Pay: $" << netpay;
                        cout << "\n\tFederal Tax Rate: " << num3*100 << "%";
                        cout << "\n\tState Tax Rate: " << num4*100 << "%\n";



                    //closes while loop
                    inputFile >> word1 >> word2 >> word3;
                    inputFile >> num1 >> num2 >> num3 >> num4;

                    }
                    inputFile.close();
                    break;
                }
            case 3:
                {

                    do
                    {
                    system("cls");
                    cin.clear();
                    cin.ignore();
                    cout << "\n\tOption 3\n";
                    cout << "\n\tFind ALL Employee Records LESS than \"N\" Work Hours"
                         << "\n\tEnter Number of Hours to Search Records (Maximum of 60.00 Hours): ";

                        cin >> searchhours;
                        searchhours = absolute(searchhours);
                    } while(searchhours > 60 | searchhours < 0);


                    ifstream inputFile;
                    inputFile.open("personnel2.dat");
                    //string word1[10], word2[10], word3[30];
                    string word1, word2, word3;
                    float num1, num2, num3, num4;
                    count = 0, counter = 0;

                    inputFile >> word1 >> word2 >> word3;
                    inputFile >> num1 >> num2 >> num3 >> num4;

                    while(!inputFile.eof())
                    {
                        count++;

                        if(num1 < searchhours)
                        {
                            //calculations
                            grosspay = num1 * num2;
                            fedrate = num3 * grosspay;
                            staterate = num4 * grosspay;
                            netpay = grosspay - fedrate - staterate;

                            cout << "\n\t\tRecord #" << count;

                            cout << "\n\tEmployee ID: " << word1;

                            cout << "\n\tEmployee Name: " << word3 << " " << word2;


                            cout << "\n\tHours Worked: " << num1;
                            cout << "\tPay Per Hour: $" << num2;
                            cout << "\tGross Pay: $" << grosspay;
                            cout << "\n\tFederal Taxes: $" << fedrate;
                            cout << "\tState Taxes: $" << staterate;
                            cout << "\tNet Pay: $" << netpay;
                            cout << "\n\tFederal Tax Rate: " << num3*100 << "%";
                            cout << "\n\tState Tax Rate: " << num4*100 << "%\n";
                            counter++;
                        }

                    //closes while loop
                    inputFile >> word1 >> word2 >> word3;
                    inputFile >> num1 >> num2 >> num3 >> num4;


                    }
                    inputFile.close();
                    if(counter == 0)
                        {
                            cout << "\n\n\tNO Records found";
                        }
                    break;
                }
            case 4:
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





        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");
    }

}

    void header()
    {
        system("cls");

        cout << "\n\t\tEnter an Option: "
             << "\n\t1 - Write new Records to the Data file"
             << "\n\t2 - Display Records From the Data file to the Screen"
             << "\n\t3 - Find ALL Employees with Work Hours LESS than \"N\" Hours"
             << "\n\t4 - QUIT";
    }
    float absolute(float var1)
    {
        if(var1 < 0)
        {
            cout << "\n\tEntered a Negative Value. Turning Previous Value to Positive. \n\t" << var1 << " to " << fabs(var1) << "\n\t";
        }
        return fabs(var1);
    }

