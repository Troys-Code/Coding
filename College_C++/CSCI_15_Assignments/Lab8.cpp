#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

//#include "Link List.h"

using namespace std;

struct node
{
    node *next = nullptr;
    int value;
    node *previous = nullptr;
};

void Display(node *temp, int size)
{
    cout << "\n\tNode # " << size << setw(3) << " Has a value of " << temp -> value << setw(3) << " Located at Address " << temp << setw (3) << " points BEHIND to " << temp -> previous << " and points NEXT to " << temp -> next;
}

int main()
{
    char again = 'y';
    int option;
    int size_nodes = 0;
    int number;

    node *FIRST = nullptr;
    node *LAST = nullptr;
    node *TEMP_Previous = nullptr;
    node *TEMP_Next = nullptr;

    node *TEMP = nullptr;
    node *TEMP2 = NULL;
    node *TEMP3 = NULL;

    //cout.precision(2);
    //cout.setf(ios::fixed | ios::showpoint);

    while(again == 'y')
    {
        //int status = 0;
        bool status = false;
        do
        {
            cout << "\n\t1 - Insert an INTEGER at the BEGINNING of the LIST"
                 << "\n\t2 - Insert an INTEGER  at the END of the LIST"
                 << "\n\t3 - Insert a NODE in the MIDDLE of the LIST"
                 << "\n\t4 - Remove a SPECIFIC INTEGER  from the LIST"
                 << "\n\t5 - TRAVERSE and Display list from BEGINNING to END"
                 << "\n\t6 - TRAVERSE and Display list in REVERSE Order"
                 << "\n\t7 - Find a Particular INTEGER in the LIST"
                 << "\n\t8 - Find a Particular INTEGER in the LIST and CHANGE it"
                 << "\n\t9 - DISPLAY first and Last Element Values"
                 << "\n\t10 - Quit";

            cout << "\n\n\tEnter an Option from 1 - 10: ";
            cin >> option;
            cin.clear();
            if(size_nodes == 0 && option > 3 && option < 9)
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
                cout << "\n\n\tEnter a Valid INTEGER: ";
                cin >> number;
                if(size_nodes == 0)
                {
                    //first_node(TEMP, FIRST, LAST, number);
                    TEMP = new node;
                    TEMP -> previous = nullptr;
                    TEMP -> next = nullptr;
                    TEMP -> value = number;
                    FIRST = TEMP;
                    LAST = TEMP;
                }
                else
                {
                    TEMP = new node;
                    TEMP -> previous = nullptr;
                    TEMP -> next = FIRST;
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
                cout << "\n\t2 - Insert an INTEGER  at the END of the LIST";
                cout << "\n\n\tEnter a Valid INTEGER: ";
                cin >> number;

                if(size_nodes == 0)
                {
                    //first_node(TEMP, FIRST, LAST, number);
                    TEMP = new node;
                    TEMP -> previous = nullptr;
                    TEMP -> next = nullptr;
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
                    LAST -> next = TEMP;
                    LAST = TEMP;
                }
                size_nodes++;
                Display(LAST, size_nodes);
                break;
            }
            case 3:
            {
                cout << "\n\t3 - Insert an INTEGER in the MIDDLE of the LIST";
                cout << "\n\tEnter a Valid INTEGER: ";
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
                    TEMP = FIRST;
                    int place = size_nodes/2;;
                    if(size_nodes % 2 != 0)
                    {
                        place = size_nodes/2 + 1;
                    }
                    for(int n = 1; n < place; n++)
                    {
                        TEMP = TEMP -> next;
                        if(place == size_nodes)
                        {
                            LAST = TEMP;
                        }
                    }
                    place++;

                    TEMP3 = TEMP -> next;

                    //Temp 2 New Middle Node
                    TEMP2 = new node;
                    //TEMP2 -> statename = state;
                    TEMP2 -> value = number;
                    TEMP2 -> next = TEMP3;
                    TEMP2 -> previous = TEMP;
                    TEMP3 -> previous = TEMP2;
                    TEMP -> next = TEMP2;

                    Display(TEMP2, place);
                }
                size_nodes++;
                break;
            }
            case 4:
            {
                cout << "\n\t4 - Remove a SPECIFIC INTEGER  from the LIST";
                cout << "\n\tWARNING: If nodes contain the same value, the program will display the FIRST Node with that value.";
                cout << "\n\n\tEnter a SPECIFIC INTEGER from the LIST to Remove: ";
                cin >> number;

                TEMP = FIRST;
                for(int n = 1; n <= size_nodes; n++)
                {
                    int Value = TEMP -> value;
                    if(Value == number)
                    {
                        cout << "\n\tRemoving. . . ";
                        Display(TEMP, n);

                        //TEMP Previous
                        TEMP2 = TEMP -> previous;
                        //TEMP Next
                        TEMP3 = TEMP -> next;

                        //So First null does not point next.
                        if(n != 1)
                        {
                            TEMP2 -> next = TEMP -> next;
                        }
                        //So Last null does not point previous.
                        if(n != size_nodes)
                        {
                            TEMP3 -> previous = TEMP -> previous;
                        }
                        size_nodes--;
                        cout << "\n\n\tPrevious Node";
                        if(n == 1)
                        {
                            FIRST = TEMP3;
                            cout << "\n\tNull. . . ";
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
                            LAST = TEMP2;
                            cout << "\n\tNull. . . ";
                        }
                        else
                        {
                            Display(TEMP3, n);
                        }
                        status++;
                        break;
                    }
                    TEMP = TEMP -> next;

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
                cout << "\n\t7 - Find a Particular INTEGER in the LIST";
                cout << "\n\tWARNING: If nodes contain the same value, the program will display the FIRST Node with that value.";
                cout << "\n\tEnter an Integer to Find: ";
                cin >> number;
                TEMP = FIRST;
                for(int n = 1; n <= size_nodes; n++)
                {
                    int Value = TEMP -> value;
                    if(Value == number)
                    {
                        Display(TEMP, n);
                        status = true;
                        break;
                    }
                    TEMP = TEMP -> next;
                }
                if(status == false)
                {
                    cout << "\n\tUnable to find " << number << " in the LIST.";
                }
                break;
            }
            case 8:
            {
                cout << "\n\t8 - Find a Particular INTEGER in the LIST and CHANGE it";
                cout << "\n\tWARNING: If nodes contain the same value, the program will display the FIRST Node with that value.";
                cout << "\n\n\tEnter an Integer to Find and Change: ";
                cin >> number;
                TEMP = FIRST;
                for(int n = 1; n <= size_nodes; n++)
                {
                    int Value = TEMP -> value;
                    if(Value == number)
                    {
                        Display(TEMP, n);
                        cout << "\n\tWould you like to Change the INTEGER? (y or n): ";
                        cin >> again;
                        again = tolower(again);
                        if(again == 'y')
                        {
                            cout << "\n\n\tEnter a new INTEGER: ";
                            cin >> number;
                            TEMP -> value = number;

                            Display(TEMP, n);
                        }
                        again == 'y';
                        status = true;
                        break;
                    }
                TEMP = TEMP -> next;
                }
                if(status == false)
                {
                    cout << "\n\tUnable to find " << number << " in the LIST.";
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
            case 10:
            {
                cout << "\n\tOption 10:"
                     << "\n\tQuitting . . . ";
                again = 'n';
                break;
            }
        }

        cout << "\n\n\tHit Any Key to Continue...";
        getch();
        system("cls");
    }

}
