#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

class arithmetic1
{
    private:
    float a1;
    float a2;

    public:
    friend class arithmetic2;

    void firstwrite(float one)
    {
        a1 = one;
    }
    void secondwrite(float two)
    {
        a2 = two;
    }
    float firstget()
    {
        return a1;
    }
    float secondget()
    {
        return a2;
    }

    arithmetic1()
    {
        a1 = 1;
        a2 = 1;
    }
};
class arithmetic2
{
    private:
    float n1;
    float n2;

    public:
    float add()
    {
        return (n1 + n2);
    }
    float subtract()
    {
        return (n1 - n2);
    }
    float multiply()
    {
        return (n1 * n2);
    }
    float divide()
    {
        float temp = n2;
        if(n2 == 0)
        {
            cout << "\n\t Setting Second Value Temporarily to 1";
            n2 = 1;
        }
        return (n1 / n2);
        n2 = temp;
    }

    void average()
    {
        float sum = n1+n2;
        float average = sum/2;
        cout << "\n\n\tAverage of " << sum << " is " << average;
    }
    void Larger()
    {

        cout << "\n\tThe Larger of " << n1 << " and " << n2 << " is ";
        if(n1 > n2)
        {
            cout << n1;
        }
        else if(n2 > n1)
        {
            cout << n1;
        }
        else
        {
            cout << "not applicable. \n\tBoth Values are Equal.";
        }
    }
    void Smaller()
    {

        cout << "\n\tThe Smaller of " << n1 << " and " << n2 << " is ";
        if(n1 > n2)
        {
            cout << n2;
        }
        else if(n2 > n1)
        {
            cout << n1;
        }
        else
        {
            cout << "not applicable. \n\tBoth Values are Equal.";
        }
    }
    void convert(arithmetic1 values)
    {
        n1 = values.a1;
        n2 = values.a2;
    }

};

int main()
{
    char again = 'y';
    arithmetic1 numbers;
    arithmetic2 temp;
    float one, two;

    /*
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);
    */

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
