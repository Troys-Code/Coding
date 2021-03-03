#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

int main( )
{
    char Again = 'y';

    int Size;
    int MaxRandom;

    int Find;


    int HighestValue = 0;
    int Highest = 0;


    do
    {

    cout << "\n\t(1 of 2) Enter the size of the Array: ";
    cin >> Size;

    cout << "\n\t(2 of 2) Enter the Maximum value of the Random Number: ";
    cin >> MaxRandom;
    int LowestValue = MaxRandom;
    int Lowest = 0;

    cout << "\n\t" << Size << " Random Numbers from 1 to " << MaxRandom << ":\n\t";
    int Rand[Size];


    for (int n = 0; n <= Size-1; n++)
    {
    Rand[n] = rand()% MaxRandom + 1;
    cout << "\n\tNumber #" << n << "\t" << Rand[n];
    }


    do
    {
        cout << "\n\n\tEnter a Value to Find in the array: ";
        cin >> Find;

        int Count = 0;
        int Unmatching = 0;
        //for (int n: Rand)
        for (int n = 0; n <= Size-1; n++)
        {

            if (Rand[n] == Find && Count == 0)
            {
                cout << "\n\t" << Find << " Found at Index #" << n;
                Count++;

            }
            else if ((Rand[n] == Find) && (Count > 0))
            {
                cout << ", #" << n;
            }
            else if (Count == 0 && Unmatching < Size-1)
            {
            Unmatching++;
            //break;
            }
            else if(Unmatching == Size-1)
            {
            cout << "\n\tNo Indexes contain " << Find << ".\n\n";
            }
        }
    cout << "\n\n\tFind another value in the Array (y or n):\n\t";
    cin >> Again;
    Again = tolower(Again);
    if (Again == 'n')
    {
            system("cls");
    }

    } while(Again == 'y');

    int Total = 0;
    int EvenCount = 0;
    int OddCount = 0;

    cout << "\n\t" << Size << " Random Numbers from 1 to " << MaxRandom << ":\n\t";
    for (int n = 0; n <= Size-1; n++)
    {
        cout << "\n\tNumber #" << n << "\t" << Rand[n];
        Total += Rand[n];
        float Average = (float)Total/Size;


        //Even/Odd Identification
        if (Rand[n] % 2 == 0)
        {
        EvenCount++;
        }
        else if(Rand[n] % 2 == 1)
        {
        OddCount++;
        }

        //Highest & Lowest value
        if (HighestValue < Rand[n])
        {
            HighestValue = Rand[n];
            Highest = n;
        }
        if (LowestValue > Rand[n])
        {
            LowestValue = Rand[n];
            Lowest = n;
        }

        //Last Print
        if (n == Size-1)
        {
            cout << "\n\n\tCombined Total of " << Size << " Array elements is " << Total;
            cout << "\n\tAverage of " << Size << " Array elements is " << Average;
            cout << "\n\tHighest value in the Array is " << HighestValue << " at Index #" << Highest;
            cout << "\n\tLowest value in the Array is " << LowestValue << " at Index #" << Lowest;
            cout << "\n\t" << OddCount << " ODD values in the array";
            cout << "\n\t" << EvenCount << " EVEN values in the array";
        }

    }


    cout << "\n\n\tRun this Again (y or n):\n\t";
    cin >> Again;
    Again = tolower(Again);

    if (Again == 'y')
    {
        system("cls");
    }


    } while(Again == 'y');

}
