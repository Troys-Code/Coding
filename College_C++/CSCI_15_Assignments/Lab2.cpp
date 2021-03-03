#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

//both work
void arithmetic(float, float, float&, float&, float&);
//void arithmetic2(float*, float*, float&, float&, float&);

int main()
{
    char again = 'y';

    float add, subtract, multiply;
    float number1, number2;

    //pointers
    //float *pnum1, *pnum2;
    //tried it, don't need it because the variables know the way home.
    //float *paddition = &add, *psubtraction = &subtract, *pmultiplication = &multiply;
    float *pnum1 = &number1;
    float *pnum2 = &number2;


    while(again == 'y')
    {
        cout << "\n\t1 of 2: Enter a Decimal Number for Variable \"number1\": ";
        cin >> *pnum1;
        //cout << "\n\n\t" << number1;


        cout << "\n\n\t2 of 2: Enter a Decimal Number for Variable \"number2\": ";
        cin >> *pnum2;
        //cout << "\n\n\t" << number2;

        //both lines work
        //arithmetic(number1, number2, add, subtract, multiply);

        arithmetic(*pnum1, *pnum2, add, subtract, multiply);

        //used for the other function
        //arithmetic2(pnum1, pnum2, add, subtract, multiply);



        cout << "\n\n\t" << number1 << " + " << number2 << " = " << add;
        cout << "\n\n\t" << number1 << " - " << number2 << " = " << subtract;
        cout << "\n\n\t" << number1 << " * " <<  number2 << " = " << multiply;



        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");
    }
}

void arithmetic(float num1, float num2, float &paddition, float &psubtraction, float &pmultiplication)
    {

        paddition = num1 + num2;
        psubtraction = num1 - num2;
        pmultiplication = num1 * num2;

    }

/*
void arithmetic2(float *num1, float *num2, float &paddition, float &psubtraction, float &pmultiplication)
    {

        paddition = *num1 + *num2;
        psubtraction = *num1 - *num2;
        pmultiplication = *num1 * *num2;

    }*/

