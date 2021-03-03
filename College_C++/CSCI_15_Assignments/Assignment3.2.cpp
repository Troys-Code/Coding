#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>
#include <sstream> // used to give string a numeric value.
using namespace std;

void header();
void conditionAKS(string, int);
void conditionBHN(string, int);
void conditionCT(string, int);
void conditionMOZ(string, int);

int main()
{
    char again = 'y';
    string customer;
    int threedigit;
    int width;

    while(again == 'y')
    {
        customer.clear();
        string numbers;
        do
        {
            header();
            cout << "\n\n\tCustomer ID can only contain 5 characters.";
            cout << "\n\tEnter a Customer ID (automatically uppercases characters): ";
            getline(cin, customer);
            width = customer.length();
            cin.clear();

            for(int n = 0; n < width; n++)
            {
                char temp;
                temp = customer[n];
                temp = toupper(temp);
                customer[n] = temp;
            }

            if(width !=5)
            {
                cout << "\n\n\t" << customer << " is not 5 characters. \n\tPlease go back and enter a new Customer ID.";
                cout << "\n\n\tHit Any Key to Continue...";
                getch();
            }
            else
            {
                if((customer[0] > 90 || customer[0] < 65) && (customer[1] > 90 || customer[1] < 65))
                {
                    cout << "\n\n\tThe First Two Positions Must be Letters (A to Z)";
                    cout << "\n\n\tHit Any Key to Continue...";
                    getch();
                }
                else
                {
                    for(int n = width-3; n < width; n++)
                    {
                        if(customer[n] < 48 || customer[n] > 57)
                        {
                            cout << "\n\n\tThe Last Three Positions Must Consist of Digit Symbols (0 to 9)";
                            cout << "\n\n\tHit Any Key to Continue...";
                            getch();
                            break;
                        }
                    }
                }
            }
        }while(width != 5);

         cout << "\n\tCustomer ID is " << customer;

            for(int n = customer.length()-3; n < customer.length(); n++)
            {
                numbers +=customer[n];
            }
            threedigit = stoi(numbers);
            cout << "\n\n\tLast Three digits is " << threedigit;
            //cout << "\n\n\tLast Three digits is " << numbers;

            switch(customer[0])
            {
                case 'A':
                case 'K':
                case 'S':
                {
                    conditionAKS(customer, threedigit);
                    //closes case A K S.
                    break;
                }

                case 'B':
                case 'H':
                case 'N':
                {
                    conditionBHN(customer, threedigit);
                    //closes case B H N.
                    break;
                }

                case 'C':
                case 'T':
                {
                    conditionCT(customer, threedigit);
                    //closes case C T.
                    break;
                }

                case 'M':
                case 'O':
                case 'Z':
                {
                    conditionMOZ(customer, threedigit);
                    //closes case M O Z.
                    break;
                }

                default:
                {
                    cout << "\n\n\tCustomer ID is Invalid";
                    cout << "\n\tDoes not Follow any of the Rules.";
                    cout << "\n\tHit Any Key to continue...";
                    getch();
                    break;
                }
            //closes entire switch(customer[0])
            }



        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        cin.ignore();
        cin.clear();
        system("cls");
    }

}
void header()
{
    system("cls");
    cout << "\n\t\tValid Customer ID Rules:"
         << "\n\t1 - A, K, S - Followed by B, C, D, Followed by 101 to 110"
         << "\n\t2 - B, H, N - Followed by A, F, G, H, Followed by 113 to 118 or 213 or 220 or 560 or 890"
         << "\n\t3 - C or T - Followed by K, L, Z, Followed by 134, 138, 145 or 246"
         << "\n\t4 - M, O, Z - Followed by A, D, F, Followed by 177 to 181 or 333 to 335";
}

void conditionAKS(string word, int threedigit)
{
    switch(word[1])
    {
        case 'B':
        case 'C':
        case 'D':
        {
            if(threedigit >= 101 && threedigit <= 110)
            {
                cout << "\n\n\tCustomer ID is Valid";
                cout << "\n\tHit Any Key to continue...";
                getch();
                break;
            }
            else
            {
                cout << "\n\n\tCustomer ID is Invalid";
                cout << "\n\tA, K, S - Followed by B, C, D, was not Followed by 101 to 110";
                cout << "\n\tHit Any Key to continue...";
                getch();
                break;
            }
        break;
        }
        default:
        {
            cout << "\n\n\tCustomer ID is Invalid";
            cout << "\n\tA, K, S was not Followed by B, C, or D.";
            break;
        }
    }
}

void conditionBHN(string word, int threedigit)
{
    switch(word[1])
    {
        case 'A':
        case 'F':
        case 'G':
        case 'H':
        {
            switch(threedigit)
            {
                case 113:
                case 114:
                case 115:
                case 116:
                case 117:
                case 118:
                case 213:
                case 220:
                case 560:
                case 890:
                {
                    cout << "\n\n\tCustomer ID is Valid";
                    cout << "\n\tHit Any Key to continue...";
                    getch();
                    break;
                    }
                default:
                {
                    cout << "\n\n\tCustomer ID is Invalid";
                    cout << "\n\tB, H, N - Followed by A, F, G, H, was not Followed by 113 to 118 or 213 or 220 or 560 or 890";
                    cout << "\n\tHit Any Key to continue...";
                    getch();
                    break;
                }
            }
            break;
        }
        default:
        {
            cout << "\n\n\tCustomer ID is Invalid";
            cout << "\n\tB, H, N was not followed by A, F, G, H.";
            cout << "\n\tHit Any Key to continue...";
            getch();
            break;
        }
    }
}

void conditionCT(string word, int threedigit)
{
    switch(word[1])
    {
        case 'K':
        case 'L':
        case 'Z':
        {
            switch(threedigit)
            {
                case 134:
                case 138:
                case 145:
                case 246:
                {
                    cout << "\n\n\tCustomer ID is Valid";
                    cout << "\n\tHit Any Key to continue...";
                    getch();
                    break;
                }
                default:
                {
                    cout << "\n\n\tCustomer ID is Invalid";
                    cout << "\n\tC, T - Followed by K, L, Z was not Followed by 134, 138, 145 or 246";
                    cout << "\n\tHit Any Key to continue...";
                    getch();
                    break;
                }
            }
        break;
        }
        default:
        {
            cout << "\n\n\tCustomer ID is Invalid";
            cout << "\n\tC, T was not followed by K, L, Z.";
            cout << "\n\tHit Any Key to continue...";
            getch();
            break;
        }
    }
}

void conditionMOZ(string word, int threedigit)
{
    switch(word[1])
    {
        case 'A':
        case 'D':
        case 'F':
        {
            switch(threedigit)
            {
                case 177:
                case 178:
                case 179:
                case 180:
                case 181:
                case 333:
                case 334:
                case 335:
                {
                    cout << "\n\n\tCustomer ID is Valid";
                    cout << "\n\tHit Any Key to continue...";
                    getch();
                    break;
                }
                default:
                {
                    cout << "\n\n\tCustomer ID is Invalid";
                    cout << "\n\tM, O, Z - Followed by A, D, F was not Followed by 177 to 181 or 333 to 335.";
                    cout << "\n\tHit Any Key to continue...";
                    getch();
                    break;
                }
            }
        break;
        }
        default:
        {
            cout << "\n\n\tCustomer ID is Invalid";
            cout << "\n\tM, O, Z was not Followed by A, D, F.";
            cout << "\n\tHit Any Key to continue...";
            getch();
            break;
        }
    }
}
