#include <cstdlib>
#include <iostream>

using namespace std;

class arithmetic
{
    private:
    float n1;
    float n2;

    public:
    void firstwrite(float one)
    {
        n1 = one;
    }
    void secondwrite(float two)
    {
        n2 = two;
    }
    float firstget()
    {
        return n1;
    }
    float secondget()
    {
        return n2;
    }
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

    friend void average(arithmetic numbers);
    friend void Larger(arithmetic numbers);
    friend void Smaller(arithmetic numbers);

    arithmetic()
    {
        n1 = 1;
        n2 = 1;
    }
};

void average(arithmetic values)
{
    float sum = values.firstget()+values.secondget();
    float average = sum/2;
    cout << "\n\n\tAverage of " << sum << " is " << average;
}
void Larger(arithmetic values)
{
    float one = values.firstget();
    float two = values.secondget();

    cout << "\n\tThe Larger of " << one << " and " << two << " is ";
    if(one > two)
    {
        cout << one;
    }
    else if(two > one)
    {
        cout << two;
    }
    else
    {
        cout << "not applicable. \n\tBoth Values are Equal.";
    }
}
void Smaller(arithmetic values)
{
    float one = values.firstget();
    float two = values.secondget();

    cout << "\n\tThe Smaller of " << one << " and " << two << " is ";
    if(one > two)
    {
        cout << two;
    }
    else if(two > one)
    {
        cout << one;
    }
    else
    {
        cout << "not applicable. \n\tBoth Values are Equal.";
    }
}

int main()
{
    char again = 'y';
    arithmetic numbers;
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

        cout << "\n\t" << one << " + " << two << " = " << numbers.add();
        cout << "\n\t" << one << " - " << two << " = " << numbers.subtract();
        cout << "\n\t" << one << " * " << two << " = " << numbers.multiply();
        if(two != 0)
        {
            cout << "\n\t" << one << " / " << two << " = " << numbers.divide();
        }
        else
        {
            cout << "\n\t" << one << " / 1 = " << numbers.divide();
        }

        average(numbers);
        Larger(numbers);
        Smaller(numbers);

        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");
    }
}
