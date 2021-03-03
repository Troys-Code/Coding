#include <stdlib.h>
#include <conio.h>
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

char again;

float arithmetic(float, float, int);

int main()
{
    double firstnum, secondnum;
    double add, subtract, multiply, divide;
    int option;


    /*
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout.setf(ios::showpoint);
    */

    again = 'y';

    while(again == 'y')
    {

    cout << "\n\t1 of 2 - Enter First Number: ";
    cin >> firstnum;
    //firstnum = stoi(firstnum);

    cout << "\n\t2 of 2 - Enter Second Number: ";
    cin >> secondnum;
    //secondnum = stoi(secondnum);

    cout << "\n\tRefreshing . . .  \n\tHit Any Key to Continue.";
    getch();
    system("cls");

    while(again == 'y')
    {
        cout << "\n\t1 - Add (" << firstnum << " + " << secondnum << ")";
        cout << "\n\t2 - Subtract (" << firstnum << " - " << secondnum << ")";
        cout << "\n\t3 - Multiplication (" << firstnum << " X " << secondnum << ")";
        cout << "\n\t4 - Divide ("<< firstnum << " / " << secondnum << ")";
        cout << "\n\t5 - ALL";
        cout << "\n\t6 - Quit";

        cout << "\n\n\tEnter an Option (1 to 6): ";
        cin >> option;
        system("cls");

        switch(option)
        {

            case 1:
            {
                add = arithmetic(firstnum, secondnum, option);
                cout << "\n\tOption 1";
                cout << "\n\n\t" << firstnum << " + " << secondnum << " = " << add;
                break;
            }

            case 2:
            {
                subtract = arithmetic(firstnum, secondnum, option);
                cout << "\n\tOption 2";
                cout << "\n\n\t" << firstnum << " - " << secondnum << " = " << subtract;
                break;
            }

            case 3:
            {
                multiply = arithmetic(firstnum, secondnum, option);
                cout << "\n\tOption 3";
                cout << "\n\n\t" << firstnum << " X " << secondnum << " = " << multiply;
                break;
            }

            case 4:
            {
                if(secondnum != 0)
                {
                    divide = arithmetic(firstnum, secondnum, option);
                    cout << "\n\tOption 4";
                    cout << "\n\n\t" << firstnum << " / " << secondnum << " = " << divide;
                }
                else
                {
                    cout << "\n\tCannot Divide by Zero.\n\tDefaulting the second number to 1.";
                    divide = arithmetic(firstnum, secondnum, option);
                    cout << "\n\n\t" << firstnum << " / 1 = " << divide;
                }
                break;
            }

            case 5:
            {
                cout << "\n\tShowing All Option Outputs";

                add = arithmetic(firstnum, secondnum, 1);
                subtract = arithmetic(firstnum, secondnum, 2);
                multiply = arithmetic(firstnum, secondnum, 3);
                divide =  arithmetic(firstnum, secondnum, 4);

                cout << "\n\n\tOption 1";
                cout << "\n\t" << firstnum << " + " << secondnum << " = " << add;

                cout << "\n\n\tOption 2";
                cout << "\n\t" << firstnum << " - " << secondnum << " = " << subtract;

                cout << "\n\n\tOption 3";
                cout << "\n\t" << firstnum << " X " << secondnum << " = " << multiply;

                cout << "\n\n\tOption 4";
                if(secondnum != 0)
                {
                    cout << "\n\t" << firstnum << " / " << secondnum << " = " << divide;
                }
                else
                {
                    cout << "\n\tCannot Divide by Zero.\n\tDefaulting the second number to 1.";
                    cout << "\n\t" << firstnum << " / 1 = " << divide;
                }
                break;
            }

            case 6:
            {
                arithmetic(firstnum, secondnum, option);
                break;
            }

            default:
                {
                    cout << "\n\tYou have Entered an Invalid Option. \n\tPlease Enter a Valid Option.";
                    break;
                }

        }


        cout << "\n\n\tHit Any Key to Continue.";
        getch();
        system("cls");
        }

    cout << "\n\n\tRun this Again (y or n):\n\t";
    cin >> again;
    again = tolower(again);
    system("cls");

    }
    cout << "\n\tEnding Program.\n\n\t";
    }

float arithmetic(float firstnum, float secondnum, int option)
{
    float add,subtract, multiply, divide;

    switch(option)
        {
            case 1:
            {
                add = firstnum + secondnum;
                return add;
                break;
            }
            case 2:
            {
                subtract = firstnum - secondnum;
                return subtract;
                break;
            }
            case 3:
            {
                multiply = firstnum * secondnum;
                return multiply;
                break;
            }
            case 4:
            {
                if(secondnum != 0)
                {
                    divide = firstnum / secondnum;
                    return divide;
                }
                else
                {
                    divide = firstnum;
                    return divide;
                }
                break;
            }
            case 6:
            {
                cout << "\n\tOption 6";
                cout << "\n\n\tQuitting";
                again = 'n';
                return 0;
                break;
            }
}

}

