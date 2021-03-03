#include <cstdlib>
#include <iostream>
#include "arithmetic.h"

int main()
{
    char again = 'y';
    arithmetic1 numbers;
    arithmetic2 temp;
    float one, two;

    while(again == 'y')
    {
        cout << "\n\t(1 of 2) Enter First Numeric Value: ";
        cin >> one;
        numbers.firstwrite(one);

        cout << "\n\n\t(2 of 2) Enter Second Numeric Value: ";
        cin >> two;
        numbers.secondwrite(two);

        temp.convert(numbers);

        cout << "\n\t" << one << " + " << two << " = " << temp.add();
        cout << "\n\t" << one << " - " << two << " = " << temp.subtract();
        cout << "\n\t" << one << " * " << two << " = " << temp.multiply();
        if(two != 0)
        {
            cout << "\n\t" << one << " / " << two << " = " << temp.divide();
        }
        else
        {
            cout << "\n\t" << one << " / 1 = " << temp.divide();
        }

        temp.average();
        temp.Larger();
        temp.Smaller();

        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");
    }
}
