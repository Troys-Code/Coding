#include <stdlib.h>
#include <conio.h>
#include <algorithm> // used for swap function
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

int main()
{
    char again = 'y';
    int option;
    int boxsize;

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    while(again == 'y')
    {
        cout << "\n\tEnter the Amount of Elements in the Array: ";
        cin >> boxsize;

        int realbox[boxsize];
        int *shadowbox[boxsize];
        int *Shadowbox[boxsize];
        //for unknown array sizes.
        //int boxsize = sizeof(realbox[])/sizeof(realbox[0]);

        for(int n = 0; n < boxsize; n++)
                {
                    shadowbox[n] = &realbox[n];
                    Shadowbox[n] = &realbox[n];
                    *shadowbox[n] = rand()%99 + 1;
                }

        while(again == 'y')
        {

        do{

        system("cls");
        cout << "\n\t\tEnter an Option"
             << "\n\t1 - Display Contents of Array 1 & Shadow Array I"
             << "\n\t2 - Sort Ascending Contents of the Array via the \"shadow\" pointer Array I:"
             << "\n\t3 - Sort Descending Contents of the Array via the \"shadow\" pointer Array II:"
             << "\n\t4 - Execute All Options.\n\n\t";

        cin >> option;

        }while(option > 4 || option < 1);

        switch(option)
        {
        case 4:
        case 1:
            {
                cout << "\n\n\tDisplaying the Contents of the Array 1:";

                for(int n = 0; n < boxsize; n++)
                {
                    cout << "\n\tIndex: " << n << setw(10) << realbox[n];
                }

                cout << "\n\n\tDisplay the Contents of the Array via the \"shadow\" pointer Array I:\n";

                for(int n = 0; n < boxsize; n++)
                {
                    cout << "\n\tIndex: " << n << setw(10) << *shadowbox[n] << " @ Memory Location: " << setw(10) << shadowbox[n];
                }
                if(option != 4)
                {
                    break;
                }
            }
        case 2:
            {
                for (int a = 0; a < boxsize-1; a++)
                {
                    for (int b = 0; b < boxsize-a-1; b++)
                    {
                        if (*shadowbox[b] > *shadowbox[b+1])
                        {
                            int *temp;
                            temp = shadowbox[b+1];
                            shadowbox[b+1] = shadowbox[b];
                            shadowbox[b] = temp;
                        }
                    }
                }

                cout << "\n\n\tDisplaying the Sorted Ascending Contents of the Array via the \"shadow\" pointer Array I:\n";

                for(int n = 0; n < boxsize; n++)
                {
                    cout << "\n\tIndex #" << n << setw(5) << *shadowbox[n] << setw(5) << " @ Memory Location " << shadowbox[n];
                }

                if(option != 4)
                {
                    break;
                }
            }
        case 3:
            {
                cout << "\n\n\tDisplaying the Sorted Descending Contents of the Array via the \"shadow\" pointer Array II:\n";

                for (int a = 0; a < boxsize-1; a++)
                {
                    for (int b = 0; b < boxsize-a-1; b++)
                    {
                        if (*Shadowbox[a] < *Shadowbox[b])
                        {
                            int *temp;
                            temp = Shadowbox[a];
                            Shadowbox[a] = Shadowbox[b];
                            Shadowbox[b] = temp;
                        }
                    }



                for(int n = 0; n < boxsize; n++)
                {
                    //Shadowbox[boxsize-n-1] = shadowbox[n];
                    cout << "\n\tIndex #" << n << setw(5) << *Shadowbox[n] << setw(5) << " @ Memory Location " << Shadowbox[n];
                }

                break;
            }
        }



        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");
    }

    cout << "\n\n\tRun This Program Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");

    }
}}




