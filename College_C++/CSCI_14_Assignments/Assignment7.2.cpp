#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>
#include <cmath>

using namespace std;


int main( )
{
    char again = 'y';
    char deal = 'y';

    int minvalue;
    int maxvalue;
    int counter;

    float ticketprice;
    float fixedcost;
    float discount;

    float discountprice;
    float grossprofit;
    float profit;

    //Max Variables
    float maxprofit;
    float maxticketcost;
    int maxpassengers;

    bool condition = false;
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);
    cout.setf(ios::showpoint);

    while(again == 'y')
    {
        maxprofit = 0;
        maxpassengers = 0;
        maxticketcost = 0;

        cout << "\n\tWelcome to the S.S. Rusty T. Buckette Cruise Ship.";


        cout << "\n\n\tThe ship's maximum carrying capacity is 500 passengers.";

        do
        {
        cout << "\n\n\t(1 of 5) Enter the proposed ticket price: $";
        cin >> ticketprice;

        if(ticketprice < 0)
        {
            cout << "\n\tYou have entered a negative value, the computer will automatically turn it into its absolute value.";
            ticketprice = fabs(ticketprice);
            cout << "\n\tProposed Ticket Price = $" << ticketprice;
            cout << "\n\tHit Any Key to Continue\n";
            getch();
            condition = true;
        }
        else if(ticketprice == 0)
        {
            cout << "\n\tYou are allowing customers to come into the ship for free."
                 << "\n\tYou will not make profit, please go back and enter a value higher than 0";
            cout << "\n\tHit Any Key to Continue\n";
            getch();
        }
        else
        {
            condition = true;
        }
        system("cls");

        }while(!condition);

        condition = false;

        do
        {
        cout << "\n\t(2 of 5) Please enter the fixed cost for the cruise: $";
        cin >> fixedcost;

        if(fixedcost < 0)
        {
            cout << "\n\tYou have entered a negative value, the computer will automatically turn it into its absolute value.";
            fixedcost = fabs(fixedcost);
            cout << "\n\tProposed Fixed Cost = $" << fixedcost;
            cout << "\n\tHit Any Key to Continue\n";
            getch();
            condition = true;
        }
        else if(fixedcost == 0)
        {
            cout << "\n\tYou cannot have a fixed cost of 0."
                 << "\n\tNothing is free in the world. Please enter a value higher than 0";
        }
        else
        {
            condition = true;
        }
        }while(!condition);

        condition = false;

        do
        {
            system("cls");
            cout << "\n\t(3 of 5) Enter the minimum acceptable number of passengers: ";
            cin >> minvalue;
            if(minvalue <= 0)
            {
                cout << "\n\tYou cannot have passengers less than or equal to 0. \n\tPlease Enter an acceptable minimum.";
                cout << "\n\n\tHit Any Key to Continue.";
                getch();
            }
            else if(minvalue > 500)
            {
                cout << "\n\tYou cannot have more than 500 passengers.  \n\tPlease Enter an acceptable minimum.";
                cout << "\n\n\tHit Any Key to Continue.";
                getch();
            }
            else
            {
                condition = true;
            }

        }while(!condition);

        condition = false;

         do
        {
            system("cls");
            cout << "\n\t(4 of 5) Enter the maximum number of passengers: ";
            cin >> maxvalue;
            if(maxvalue < minvalue)
            {
                cout << "\n\tYour maximum cannot be less than " << minvalue << " passengers."
                     << "\n\tPlease Enter an acceptable maximum."
                     << "\n\n\tHit Any Key to Continue.";
                getch();
            }
            else if(maxvalue > 500)
            {
                cout << "\n\tYou cannot have more than 500 passengers. \n\tPlease Enter an acceptable maximum.";
                cout << "\n\n\tHit Any Key to Continue.";
                getch();
            }
            else
            {
                condition = true;
                system("cls");
            }

        }while(!condition);

        cout << "\n\t(5 of 5) Enter the discount per ticket per every group of 10 passengers: $";
        cin >> discount;
        if(discount < 0)
        {
            cout << "\n\tYou have entered a negative value, the computer will automatically turn it into its absolute value.";
            discount = fabs(discount);
            cout << "\n\tDiscount Per Ticket Per Every Group of 10 Passengers = $" << discount;
            cout << "\n\n\tHit Any Key to Continue.";
            getch();
        }
        else if(discount == 0)
        {
            cout << "\n\tNo discount will be applied per ticket per every group of 10 passengers";
            cout << "\n\n\tHit Any Key to Continue.";
            getch();
        }

        system("cls");

        cout << setw(15) << "Number" << setw(16) << "Ticket\n";
        cout << setw(15) << "\tPassengers" << setw(11) << "Price" << setw(15) << "Gross" << setw(15) << "\tFixed Cost" << setw(13) << "Profit\n";



        for(int numpassengers = minvalue; numpassengers <= maxvalue; numpassengers+=10)
        {
        //Calculations
        discountprice = ticketprice - ((numpassengers-minvalue)/10 * discount);
        grossprofit = numpassengers * discountprice;
        profit = (grossprofit) - fixedcost;

        if(profit > maxprofit)
        {
             maxprofit = profit;
             maxticketcost = discountprice;
             maxpassengers =  numpassengers;
        }

        if(discountprice != 0)
        {
            cout << "\n\t" << numpassengers << "\t\t$" << setw(2) << discountprice << setw(5) << "\t$" << setw(2)
                 << grossprofit << "\t\t$" << setw(2) << fixedcost << "\t$" << setw(2) << profit;
        }
        else
        {
            condition = false;
            cout << "\n\n\tThe cost of the ticket is equal to 0. If the code continues the ticket price will be negative.";
            cout << "\n\tWould you like to continue the loop? (Y or N): ";
            cin >> deal;
            deal = tolower(deal);
                if(deal == 'n')
                {
                    break;
                }
        }
        if(discountprice > 0)
        {
            condition = true;
        }


        }

        if(condition == true)
        {
            cout << "\n\n\n\tMaximum Profit is $" << maxprofit;
            cout << "\n\tTicket Cost to Generate Maximum Profit is $" << maxticketcost;
            cout << "\n\tPassengers Needed to Generate Maximum Profit is " << maxpassengers;
        }
        else
        {
            cout << "\n\n\tYou did not make money during the deal, you backed out.";

        }

        cout << "\n\n\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");
    }

    cout << "\n\tEnding Program";

}

