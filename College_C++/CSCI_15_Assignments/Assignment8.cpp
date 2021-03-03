#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>
#include <fstream>

//#include "Link List.h"

using namespace std;

struct node
{
    node *next = nullptr;
    string statename;
    int value;
    node *previous = nullptr;
};

void Display(node *temp, int size)
{
    cout << "\n\tNode # " << setw(4) << size << " :" << setw(20) << temp -> statename << setw(10) << temp -> value;
    cout << setw(20) << " Previous: " << setw(10) << temp -> previous << setw(13) << "Actual: " << temp << setw(9) << " Next: " << temp -> next;
}

int main()
{
    //char again = 'y';
    int option;
    int size_nodes = 0;
    int number;
    string state;
    char again;

    node *FIRST = nullptr;
    node *LAST = nullptr;
    node *TEMP_Previous = nullptr;
    node *TEMP_Next = nullptr;

    node *TEMP = nullptr;
    node *TEMP2 = NULL;
    node *TEMP3 = NULL;

    ifstream InputFile;
    InputFile.open("States2.dat", ios::in);
    TEMP = new node;
    TEMP -> previous = nullptr;
    TEMP -> next = nullptr;
    FIRST = TEMP;
    LAST = TEMP;
    InputFile >> TEMP -> statename >> TEMP -> value;
    size_nodes++;

    while(!InputFile.eof())
    {
        TEMP = new node;
        TEMP -> previous = LAST;
        TEMP -> next = nullptr;
        InputFile >> TEMP -> statename >> TEMP -> value;
        LAST -> next = TEMP;
        LAST = TEMP;

        //we don't need this line
        //TEMP = TEMP -> next;

        size_nodes++;
    }

    InputFile.close();
    if(size_nodes == 0)
    {
        cout << "\n\n\tNO RECORDS FOUND";
    }
    else
    {
        //Include this because your "end of file marker" (\n) is read and put into a node.
        size_nodes--;
        LAST = TEMP -> previous;
        LAST -> next = nullptr;
    }

    while(option != 10)
    {
        //int status = 0;
        bool status = false;
        do
        {
            cout << "\n\t1 - Insert a NODE at the BEGINNING of the LIST"
                 << "\n\t2 - Insert a NODE at the END of the LIST"
                 << "\n\t3 - Insert a NODE in the MIDDLE of the LIST"
                 << "\n\t4 - Remove a SPECIFIC NODE from the LIST"
                 << "\n\t5 - TRAVERSE and Display list from BEGINNING to END"
                 << "\n\t6 - TRAVERSE and Display list in REVERSE Order"
                 << "\n\t7 - Find a Particular NODE in the LIST"
                 << "\n\t8 - Find a Particular NODE in the LIST and CHANGE it"
                 << "\n\t9 - DISPLAY First and Last Element Values"
                 << "\n\t10 - Quit";

            cout << "\n\n\tEnter an Option from 1 - 10: ";
            cin >> option;
            cin.clear();
            cin.ignore();
            if(size_nodes == 0 && option > 3 && option < 10)
            {
                cout << "\n\tList is Empty, Please go back to the menu";
                cout << "\n\tHit Any Key to Continue...";
                getch();
                option = -1;
            }
            system("cls");
        }while(option < 1 || option > 10);

        switch(option)
        {
            case 1:
            {
                cout << "\n\t1 - Insert an INTEGER at the BEGINNING of the LIST";
                cout << "\n\t(1 of 2) Enter a Valid STATE NAME: ";
                getline(cin, state);
                cout << "\n\t(2 of 2) Enter a Valid INTEGER: ";
                cin >> number;

                if(size_nodes == 0)
                {
                    //first_node(TEMP, FIRST, LAST, number);
                    TEMP = new node;
                    TEMP -> previous = nullptr;
                    TEMP -> next = nullptr;
                    TEMP -> statename = state;
                    TEMP -> value = number;
                    FIRST = TEMP;
                    LAST = TEMP;
                }
                else
                {
                    TEMP = new node;
                    TEMP -> previous = nullptr;
                    TEMP -> next = FIRST;
                    TEMP -> statename = state;
                    TEMP -> value = number;
                    FIRST -> previous = TEMP;
                    FIRST = TEMP;
                }
                size_nodes++;
                Display(FIRST, 1);
                break;
            }
            case 2:
            {
                cout << "\n\t2 - Insert a NODE at the END of the LIST";
                cout << "\n\t(1 of 2) Enter a Valid STATE NAME: ";
                getline(cin, state);
                cout << "\n\n\t(2 of 2) Enter a Valid INTEGER: ";
                cin >> number;

                if(size_nodes == 0)
                {
                    //first_node(TEMP, FIRST, LAST, number);
                    TEMP = new node;
                    TEMP -> previous = nullptr;
                    TEMP -> next = nullptr;
                    TEMP -> statename = state;
                    TEMP -> value = number;
                    FIRST = TEMP;
                    LAST = TEMP;
                }
                else
                {
                    TEMP = new node;
                    TEMP -> previous = LAST;
                    TEMP -> next = nullptr;
                    TEMP -> value = number;
                    TEMP -> statename = state;
                    LAST -> next = TEMP;
                    LAST = TEMP;
                }
                size_nodes++;
                Display(LAST, size_nodes);
                break;
            }
            case 3:
            {
                int place;
                bool chingu = true;
                int temporary;
                do
                {
                    cout << "\n\t3 - Insert a NODE in the MIDDLE of the LIST";
                    cout << "\n\n\tWhat \"value\" would you like to place the node \"after\"? : ";
                    cin >> temporary;
                    cin.clear();
                    cin.ignore();
                    TEMP = FIRST;
                    again = 'y';
                    for(int n = 1; n <= size_nodes; n++)
                    {
                        int Value = TEMP -> value;
                        if(Value == temporary)
                        {
                            chingu = false;
                            Display(TEMP,n);
                            cout << "\n\tMay Have Found Multiple Same State Values..."
                                 << "\n\tWould you like to add after this state? (y or n): ";
                            cin >> again;
                            again = tolower(again);

                            if(again == 'y')
                            {
                                cout << "\n\tPlacing a new node after ";
                                Display(TEMP, n);
                                place = n;
    //                            cout << "\n\t" << n;
    //                            getch();
                                break;
                            }
                        system("cls");
                        }
                        if(n != size_nodes)
                        {
                            TEMP = TEMP -> next;
                        }
                    }
                    if(chingu)
                    {
                        cout << "\n\tNo State Value found in the Data File";
                        cout << "\n\n\tHit Any Key to Continue...";
                        getch();
                        system("cls");
                    }
                }while(chingu && size_nodes != 0);

                if(again == 'y')
                {
                    cout << "\n\n\t(1 of 2) Enter a Valid STATE NAME: ";
                    cin.clear();
                    cin.ignore();
                    getline(cin, state);
                    cout << "\n\t(2 of 2) Enter a Valid INTEGER: ";
                    cin >> number;

                    if(size_nodes == 0)
                    {
                        //first_node(TEMP, FIRST, LAST, number);
                        TEMP = new node;
                        TEMP -> previous = nullptr;
                        TEMP -> next = nullptr;
                        //TEMP -> statename = state;
                        TEMP -> value = number;
                        FIRST = TEMP;
                        LAST = TEMP;
                        Display(TEMP, 1);
                    }
                    else
                    {
                        TEMP3 = TEMP -> next;
                        //Temp2 New Middle Node
                        TEMP2 = new node;
                        TEMP2 -> statename = state;
                        TEMP2 -> value = number;

                        TEMP2 -> next = TEMP3;
                        TEMP2 -> previous = TEMP;
                        TEMP3 -> previous = TEMP2;
                        if(TEMP -> next == nullptr)
                        {
                            LAST = TEMP2;
                        }
                        TEMP -> next = TEMP2;


                        Display(TEMP2, place+1);
                    }
                    size_nodes++;
                }
                break;
            }
            case 4:
            {
                cout << "\n\t4 - Remove a Node based on STATE NAME from the LIST";
                cout << "\n\tEnter a STATE NAME from the LIST to Remove: ";
                getline(cin, state);

                TEMP = FIRST;
                for(int n = 1; n <= size_nodes; n++)
                {
                    string Value = TEMP -> statename;
                    again = 'y';
                    if(Value == state)
                    {
                        Display(TEMP,n);
                        cout << "\n\tMay have found multiple Same State Names..."
                             << "\n\tWould you like to remove this state? (y or n): ";
                        cin >> again;
                        again = tolower(again);

                        if(again == 'y')
                        {
                            cout << "\n\tRemoving. . . ";
                            Display(TEMP, n);

                            //TEMP Previous
                            TEMP2 = TEMP -> previous;
                            //TEMP Next
                            TEMP3 = TEMP -> next;
                            if(n != 1)
                            {
                                TEMP2 -> next = TEMP -> next;
                            }
                            if(n != size_nodes)
                            {
                                TEMP3 -> previous = TEMP -> previous;
                            }
                            size_nodes--;
                            cout << "\n\n\tPrevious Node";
                            if(n == 1)
                            {
                                cout << "\n\tNull. . . ";
                                FIRST = TEMP3;
                            }
                            else
                            {
                               Display(TEMP2, n-1);
                            }
                            cout << "\n\n\tNext Node";

                            if(n == 1 && size_nodes != 0)
                            {
                               Display(TEMP3, n);
                            }
                            else if(n == size_nodes+1 || size_nodes == 0)
                            {
                                cout << "\n\tNull. . . ";
                                LAST = TEMP2;
                            }
                            else
                            {
                                Display(TEMP3, n+1);
                            }
                        }
                        system("cls");
                        status++;
                    }
                TEMP = TEMP -> next;
                //Outside For Loop
                }
                if(status == 0)
                {
                    cout << "\n\tUnable to find INTEGER to Remove.";
                }
                break;
            }
            case 5:
            {
                cout << "\n\t5 - TRAVERSE and Display list from BEGINNING to END";
                cout << "\n\tList has " << size_nodes << " elements (using Next)";
                TEMP = FIRST;
                for(int n = 1; n <= size_nodes; n++)
                {
                    Display(TEMP,n);
                    TEMP = TEMP -> next;
                }
                cout << "\n\tNULL - End of List";
                break;
            }
            case 6:
            {
                cout << "\n\t6 - TRAVERSE and Display list in REVERSE Order";
                cout << "\n\tList has " << size_nodes << " elements (using Previous)";
                TEMP = LAST;
                for(int n = size_nodes; n >= 1; n--)
                {
                    Display(TEMP,n);
                    TEMP = TEMP -> previous;
                }
                cout << "\n\tNULL - End of List";
                break;
            }
            case 7:
            {
                cout << "\n\t7 - Find a Particular STATE in the LIST";
                cout << "\n\n\tEnter a STATE NAME to Find: ";
                getline(cin, state);
                TEMP = FIRST;
                for(int n = 1; n <= size_nodes; n++)
                {
                    string Value = TEMP -> statename;
                    if( state == Value)
                    {
                        Display(TEMP, n);
                        status = true;
                    }
                    TEMP = TEMP -> next;
                }
                if(status == false)
                {
                    cout << "\n\tUnable to find " << state << " in the LIST.";
                }
                break;
            }
            case 8:
            {
                cout << "\n\t8 - Find a Particular STATE NAME in the LIST and CHANGE it";
                cout << "\n\n\tEnter a STATE NAME to Find and Change: ";
                getline(cin, state);
                cin.clear();
                TEMP = FIRST;
                for(int n = 1; n <= size_nodes; n++)
                {
                    string Value = TEMP -> statename;
                    if(state == Value)
                    {
                        do
                        {
                            Display(TEMP, n);
                            cout << "\n\n\t1 - Change State Name"
                                 << "\n\t2 - Change Integer"
                                 << "\n\t3 - Quit Changes";
                            cout << "\n\n\tEnter an Option: ";
                            cin >> option;
                            cin.clear();
                            cin.ignore();

                            switch(option)
                            {
                                case 1:
                                {
                                    cout << "\n\n\tEnter a new State Name: ";
                                    getline(cin, state);
                                    TEMP -> statename = state;

                                    Display(TEMP, n);
                                    cout << "\n\n\tHit Any Key to Continue...";
                                    getch();
                                    break;
                                }
                                case 2:
                                {
                                    cout << "\n\n\tEnter a new INTEGER: ";
                                    cin >> number;
                                    TEMP -> value = number;

                                    Display(TEMP, n);
                                    cout << "\n\n\tHit Any Key to Continue...";
                                    getch();
                                    break;
                                }
                            }
                        system("cls");
                        }while(option != 3);
                        status = true;
                    }
                TEMP = TEMP -> next;
                }
                if(status == false)
                {
                    cout << "\n\tUnable to find " << state << " in the LIST.";
                }
                break;
            }
            case 9:
            {
                cout << "\n\t9 - DISPLAY first and Last Element Values";
                Display(FIRST, 1);
                Display(LAST, size_nodes);
                break;
            }
        }
        if(option != 10)
        {
            cout << "\n\n\tHit Any Key to Continue...";
            getch();
            system("cls");
        }
    }
    cout << "\n\tQuitting . . . ";
    cout << "\n\n\tHit Any Key to Continue...";
    getch();
    system("cls");

    ofstream outputFile;
    outputFile.open("States2.dat", ios::out);

    TEMP = FIRST;
    for(int n = 1; n <= size_nodes; n++)
    {
        outputFile << TEMP -> statename << " " << TEMP -> value;
        outputFile << "\n";
        TEMP = TEMP -> next;
    }
    outputFile.close();
}
