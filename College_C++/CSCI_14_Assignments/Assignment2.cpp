#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

int main( )
{
    float Amount_Milk = 0.0, Amount_Dark = 0.0, Amount_White = 0.0, Amount_European = 0.0;
    float Cost_Milk = 8.50F, Cost_Dark = 9.75F, Cost_White = 10.50F, Cost_European = 12.50F;
    float Total_Milk, Total_Dark, Total_White, Total_Eurpoean;

    float Discount10 = 0.1F, Discount15 = 0.15F, Discount20 = 0.2F, Discount25 = 0.25F;

    float Shipping_Handeling_Fee;
    float Shipping_Handeling_Percentage = 0.1F;
    float Net_Total;
    float Discount_Total;
    float Grand_Total;

    float Discount_Number = 0.00;

    int Discount_ID;

    char choice;

    cout.setf(ios::fixed | ios::showpoint);

    //Text 1
    cout << "\n\tThe store sells chocolates:";
    cout << "\n\tMilk Chocolate @ $" << setprecision(2) << Cost_Milk << " per pound";
    cout << "\n\tDark Chocolate @ $" << Cost_Dark << " per pound";
    cout << "\n\tWhite Chocolate @ $" << Cost_White << " per pound";
    cout << "\n\tEuropean Chocolate @ $" << Cost_European << " per pound";

    //Text 2
    cout << "\n\n\tThe store allows a customer discount based on:";
    cout << "\n\t1.  $20.00 to $39.99 \t10% off";
    cout << "\n\t2.  $40.00 to $59.99 \t15% off";
    cout << "\n\t3.  $60.00 to $79.99 \t20% off";
    cout << "\n\t4.  $80.00 and over \t25% off";


        cout << "\n\n\tHow many pounds of Milk Chocolate would you like to order? (Ex. 2.00)\n\t";
        cin >> Amount_Milk;

        cout << "\n\tHow many pounds of Dark Chocolate would you like to order? (Ex. 2.00)\n\t";
        cin >> Amount_Dark;

        cout << "\n\tHow many pounds of White Chocolate would you like to order? (Ex. 2.00)\n\t";
        cin >> Amount_White;

        cout << "\n\tHow many pounds of Dark Chocolate would you like to order? (Ex. 2.00)\n\t";
        cin >> Amount_European;

    cout << "\n\tHit Any Key To Continue";
    getch();
    system("cls");

    //Total Calculation
    Total_Milk = (Amount_Milk * Cost_Milk);
    Total_Dark = (Amount_Dark * Cost_Dark);
    Total_White = (Amount_White * Cost_White);
    Total_Eurpoean = (Amount_European * Cost_European);

    Net_Total = Total_Milk + Total_Dark + Total_White + Total_Eurpoean;


    if((Net_Total >= 20.0) && (Net_Total <= 39.99))
    {
        Discount_ID = 1;
    }
    else if((Net_Total >= 40.0) && (Net_Total <=59.99))
    {
        Discount_ID = 2;
    }
    else if((Net_Total >= 60.0) && (Net_Total <=79.99))
    {
        Discount_ID = 3;
    }
    else if(Net_Total >= 80.0)
    {
        Discount_ID = 4;
    }

    //Discount Calculation
    switch(Discount_ID)
    {

        case 1:
        {
            Discount_Total = (Net_Total - (Net_Total * Discount10));
            Discount_Number = Discount10;
            break;
        }

        case 2:
        {
            Discount_Total = (Net_Total - (Net_Total * Discount15));
            Discount_Number = Discount15;
            break;
        }

        case 3:
        {
            Discount_Total = (Net_Total - (Net_Total * Discount20));
            Discount_Number = Discount20;
            break;
        }

        case 4:
        {
            Discount_Total = (Net_Total - (Net_Total * Discount25));
            Discount_Number = Discount25;
            break;
        }

    }


    cout << "\n\t\tInvoice Order";

    cout << "\n\n\t";

    //Don't have to set it equal to 0.00

    if (Amount_Milk != 0.00)
    {
        cout << Amount_Milk << " lbs of Milk Chocolate Ordered @ " << Cost_Milk << " per lb\t$" << Total_Milk << "\n\t";
    }
    if (Amount_Dark != 0.00)
    {
        cout << Amount_Dark << " lbs of Dark Chocolate Ordered @ " << Cost_Dark << " per lb\t$" << Total_Dark << "\n\t";
    }
    if (Amount_White != 0.00)
    {
        cout << Amount_White << " lbs of White Chocolate Ordered @ " << Cost_White << " per lb\t$" << Total_White << "\n\t";
    }
    if (Amount_European != 0.00)
    {
        cout << Amount_European << " lbs of European Chocolate Ordered @ " << Cost_European << " per lb\t$" << Total_Eurpoean;
    }


    cout << "\n\n\tTotal Order is\t\t\t\t\t\t$" << Net_Total;

    if (Discount_Number != 0.00)
    {
    Discount_Total = Net_Total * Discount_Number;
    cout << "\n\tLess: Discount of " << (Discount_Number * 100) << "%\t\t\t\t$" << (Discount_Total);
    }

    cout << "\n\n\tOrder is \t\t\t\t\t\t$" << (Net_Total - Discount_Total);

    //Shipping & Handling Fee Calculation
    Shipping_Handeling_Fee = ((Shipping_Handeling_Percentage) * (Net_Total - Discount_Total));
    cout << "\n\tShipping and Handling @ " << (Shipping_Handeling_Percentage * 100) << "% (based on $" << (Net_Total - Discount_Total) << ")\t$" << Shipping_Handeling_Fee;

    cout << "\n\tGrand Total is\t\t\t\t\t\t$" << (Net_Total -Discount_Total + Shipping_Handeling_Fee);




}
