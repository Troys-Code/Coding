#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>


using namespace std;

int main( )
{
    //string Account_Number;
    char Account_Number[7];

    //int I.D_Whizbangs, I.D_Gizmos, I.D_Widgets, I.D_Wabbits, I.D_Elmers;
    int Amount_Whizbangs, Amount_Gizmos, Amount_Widgets, Amount_Wabbits, Amount_Elmers;

    float Cost_Whizbangs, Cost_Gizmos, Cost_Widgets, Cost_Wabbits, Cost_Elmers;

    float Whizbangs, Gizmos, Widgets, Wabbits, Elmers;

    float Sales_Tax, Shipping_Handeling_Fee, Pre_Total, Grand_Total;

    //Set Cost
    Cost_Whizbangs = 5.00F;
    Cost_Gizmos = 10.15F;
    Cost_Widgets = 5.99F;
    Cost_Wabbits = 7.75F;
    Cost_Elmers = 9.50F;

    //Used to make decimals 0.00
    //std::cout << std::setprecision(2) << std::fixed;
    //cout.setprecision(2);
    //cout.setf(ios::fixed | ios::showpoint);
    //cout << setprecision(2) << fixed;

cout.precision(2);
cout.setf(ios::fixed, ios::floatfield);
cout.setf(ios::showpoint);



    cout << "\n\tPlease Enter your account number. \n\tCustomer Account #";
    cin >> Account_Number;


    //Adjust Position Of Item Orientation

    cout << "\n\tWhizbangs cost $" << Cost_Whizbangs << "\n\tHow many Whizbangs would you like to order? \n\t";
    Amount_Whizbangs = (float)Amount_Whizbangs;
    cin >> Amount_Whizbangs;
    Amount_Whizbangs = (int)Amount_Whizbangs;


    cout << "\n\tGizmos cost $" << Cost_Gizmos << "\n\tHow many Gizmos would you like to order? \n\t";
    cin >> Amount_Gizmos;


    cout << "\n\tWidgets cost $" << Cost_Widgets << "\n\tHow many Widgets would you like to order? \n\t";
    cin >> Amount_Widgets;


    cout << "\n\tWabbits cost $" << Cost_Wabbits << "\n\tHow many Wabbits would you like to order? \n\t";
    cin >> Amount_Wabbits;


    cout << "\n\tElmers cost $" << Cost_Elmers << "\n\tHow many Elmers would you like to order? \n\t";
    cin >> Amount_Elmers;



    cout << "\n\tHit Any Key To Continue";
    getch();
    system("cls");

    //Prints Subtotal, Shipping & Handling, Sales Tax, and Grand Total

    //Calculated Cost
    Whizbangs = Amount_Whizbangs * Cost_Whizbangs;
    Gizmos = Amount_Gizmos * Cost_Gizmos;
    Widgets = Amount_Widgets * Cost_Widgets;
    Wabbits = Amount_Wabbits * Cost_Wabbits;
    Elmers = Amount_Elmers * Cost_Elmers;
    Pre_Total = Whizbangs + Gizmos + Widgets + Wabbits + Elmers;
    Sales_Tax = Pre_Total * 0.095;
    Shipping_Handeling_Fee = (Pre_Total + Sales_Tax) * 0.1;
    Grand_Total = Whizbangs + Gizmos + Widgets + Wabbits + Elmers;


    cout << "\n\n\tCustomer Account # " << Account_Number;

    cout << "\n\tNumber of Whizbangs:\t" << Amount_Whizbangs << " X " << Cost_Whizbangs << " =\t$" << Whizbangs;
    cout << "\n\tNumber of Gizmos:\t" << Amount_Gizmos << " X " << Cost_Gizmos << " =\t$" << Gizmos;
    cout << "\n\tNumber of Widgets:\t" << Amount_Widgets << " X " << Cost_Widgets << " =\t$" << Widgets;
    cout << "\n\tNumber of Wabbits:\t" << Amount_Wabbits << " X " << Cost_Wabbits << " =\t$" << Wabbits;
    cout << "\n\tNumber of Elmers:\t" << Amount_Elmers << " X " << Cost_Elmers << " =\t$" << Elmers;
    cout << "\n\n\tSubtotal \t\t\t\t$" << Pre_Total;

    cout << "\n\tSales Tax (@ 9.95%)\t\t\t$" << Sales_Tax;
    cout << "\n\tShipping & Handling (@ 10%)\t\t$" << Shipping_Handeling_Fee;

    cout << "\n\t\t\t\t\t\t=======";

    cout << "\n\tGrand Total Owned \t\t\t$" << Grand_Total;

}

