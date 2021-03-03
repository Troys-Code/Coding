
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <conio.h>


using namespace std;


//Functions
float INPUT (bool);


int main()
{

//Loop App
    char AGAIN = 'y';

    while ((AGAIN == 'y') or (AGAIN == 'Y'))
    {

//Variables
        float FCOST, DISCOUNT, PRICE;
        int MIN, MAX;
        float OPRICE, OGROSS, OPROFIT, MAX_PROFIT, MAX_PRICE; // OUTPUT and MAX Locations, Values
        int LOSS_PASSENGERS, MAX_PASSENGERS, UP_PASSENGERS, DOWN_PASSENGERS;
        bool REPEAT, PROFITUP, PROFITDOWN;

//Set Precision
        cout.precision(2);
        cout.setf(ios::fixed, ios::floatfield);
        cout.setf(ios::showpoint);

//Initialization
        MIN = 0;
        MAX = 0;
        MAX_PROFIT = -1;
        MAX_PRICE = 0;
        MAX_PASSENGERS = 0;
        LOSS_PASSENGERS = 0;
        UP_PASSENGERS = 0;

        REPEAT = false;
        PROFITUP = false;

//Input
        cout << "\n\tS.S Rusty T. Buckette Profit Calculator";

        cout << "\n\n\tEnter Minimum Number Of Passengers : ";
        MIN = (int) INPUT (true);

        cout << "\n\tEnter Maximum Number Of Passengers (Min " << MIN << " And Max 500) : ";

//Check max is greater than min
        do
        {
            MAX = (int) INPUT (true);

            if (MIN > MAX)
            {
                cout << "\n\tEnter A Value Greater Than " << MIN;
            }
        }
        while (MIN > MAX);

        cout << "\n\tEnter The Fixed Cost Of The Cruise : $";
        FCOST = INPUT (false);

        cout << "\n\tEnter Ticket Price : $";
        PRICE = INPUT(false);

        cout << "\n\tEnter The Discount Per Every 10 Tickets : $";
        DISCOUNT = INPUT(false);

        system("cls");

//Output
        cout << "\n\tS.S Rusty T. Buckette Profit Calculations";
        cout << "\n\n\t" << "Passengers" << setw(10) << "Price" << setw(12) <<  "Gross" << setw(20) << "Fixed Cost" << setw(13) << "Profit";


        for (int OPASSENGERS = MIN; OPASSENGERS <= MAX; OPASSENGERS += 10)
        {

//Calculations
            OPRICE = PRICE - (((OPASSENGERS - MIN)/10)*DISCOUNT);
            OGROSS = OPRICE * OPASSENGERS;
            OPROFIT = (OPASSENGERS * OPRICE) - FCOST;

    //Max
            if (MAX_PROFIT < OPROFIT)
            {
                MAX_PROFIT = OPROFIT;
                MAX_PRICE = OPRICE;
                MAX_PASSENGERS = OPASSENGERS;
            }

    //Bad deals
            if ((OPROFIT >= 0) and (REPEAT == true) and (PROFITUP == false))
            {
                UP_PASSENGERS = OPASSENGERS;
                PROFITUP = true;
            }

            if ((OPROFIT >= 0) and (REPEAT == true))
            {
                REPEAT = false;
            }

            if ((OPROFIT < 0) and (REPEAT == false))
            {
                LOSS_PASSENGERS = OPASSENGERS;
                REPEAT = true;
            }

            if ((OPRICE < 0))
            {
                cout << "\n\n\tUh-Oh! Your Ticket Price Is Below 0";
                cout << "\n\tYou Will Have To Pay The Committe If More Than " << OPASSENGERS << " Attend";
                break;
            }

//Output
            cout << "\n" << setw(7) << OPASSENGERS << setw(13) << "$" << setw(7) << OPRICE << setw(5) << "$" << setw(9) << OGROSS << setw(6) << "$" << setw(9) << FCOST << setw(8) << "$" << setw(9) << OPROFIT;

        }

//Output
        cout << "\n\n\n\tResults";

        if (MAX_PROFIT >= 0)
        {
            cout << "\n\n\tThe Max Profit Is $" << MAX_PROFIT;
            cout << "\n\tThe Ticket Cost When Maximum Profit Occurs Is $" << MAX_PRICE;
            cout << "\n\tThe Number Of Passengers Needed To Generate The Maximum Profit Is " << MAX_PASSENGERS << "\n";
        }
        else
        {
            cout << "\n\n\tYou Will Always Lose Money";
            cout << "\n\tThis Is A Bad Deal";

            PROFITUP = false;
            REPEAT = false;
        }

        if (PROFITUP == true)
        {
            cout << "\n\tYou Will Lose Money If Less Than " << UP_PASSENGERS << " Passengers Attend The Fundraiser";
        }

        if (REPEAT == true)
        {
            cout << "\n\tYou Will Lose Money If More Than " << LOSS_PASSENGERS << " Passengers Attend The Fundraiser";
        }

        if ((REPEAT == true) or (PROFITUP == true))
        {
            cout << "\n\n\tThis Is A Risky Deal";
        }

        cout << "\n\n\tPress Any Key To Continue";
        getch();


        cout << "\n\n\tRun This Again (y or n) : ";
        cin >> AGAIN;

        cin.clear();
        system ("cls");
    }
}

//Definitions

//Input and Filter
float INPUT (bool CHECK)
{
    float IN;
    float OUT, COUNT = 0;


    if (CHECK)
    {

        do
        {
            if (COUNT > 0)
            {
                cout << "\n\tEnter A Value Within The Above Parameters (Max 500) : ";
            }

            cin >> IN;
            cin.clear();

            COUNT++;

            OUT = IN;
        }
        while ((OUT < 0) or (OUT > 500));

    }
    else
    {
        cin >> IN;
        cin.clear();

        OUT = IN;
    }

    return OUT;
}

