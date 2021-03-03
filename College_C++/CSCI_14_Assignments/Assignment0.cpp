#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

float filter(float, float, float);
float payrollcalculations(float, float, float, float, float, int);

int main( )
{
    char again = 'y';

    string full_name, employee_id;
    int option;
    float reghours, overtimehours = 0, payrate, fedrate, staterate;
    float regpay, overtime, grosspay, fedtax, statetax, socials, medicare, netpay;

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    while(again == 'y')
    {

    cout << "\n\t1 of 6 - Enter Employee's Full Name: ";
    getline(cin, full_name);

    cout << "\n\t2 of 6 - Enter Employee ID: ";
    getline(cin, employee_id);

    cout << "\n\t3 of 6 - Enter Employee Hours (0 to 60 hours): ";
    cin >> reghours;
    reghours = filter(0,60,reghours);
    if(reghours > 40)
    {
        overtimehours = reghours - 40;
        reghours = 40;
    }

    cout << "\n\t4 of 6 - Enter Employee Pay Per Hour ($10.75 to $99.99): ";
    cin >> payrate;
    payrate = filter(10.75,99.99,payrate);

    cout << "\n\t5 of 6 - Enter Employee Federal Tax Rate (e.g. .05 is 5% or 5 is 5%, cannot be greater than 50%): ";
    cin >> fedrate;

    if(fedrate < 1)
    {
        fedrate = filter(0,0.5,fedrate);
    }
    else if(fedrate >= 1)
    {
        fedrate = filter(0,50,fedrate);
        fedrate = fedrate/100;
    }

    cout << "\n\t6 of 6 - Enter Employee State Tax Rate (e.g. .05 is 5% or 5 is 5%, cannot be greater than 30%): ";
    cin >> staterate;
    if(staterate < 1)
    {
        staterate = filter(0,0.3,staterate);
    }
    else if(staterate >= 1)
    {
        staterate = filter(0,30,staterate)/100;
    }



    system("cls");
    while(again == 'y')
    {
        cout << "\n\tSelect a Payroll Option for " << full_name;

        cout << "\n\t1 - Gross Pay"
             << "\n\t2 - Federal Taxes Withheld @ " << fedrate*100 << "%"
             << "\n\t3 - State Taxes Withheld @ " << staterate*100 << "%"
             << "\n\t4 - Medicare Withheld (1.45% of Gross)"
             << "\n\t5 - Social Security Withheld (6.20% of Gross)"
             << "\n\t6 - Net Pay (Less all Deductions)"
             << "\n\t7 - Regular Pay on " << reghours <<  " Regular Hours"
             << "\n\t8 - Overtime Pay on " << overtimehours << " Overtime Hours (1.5 times $" << payrate << ")"
             << "\n\t9 - All Payroll Calculations"
             << "\n\t10 - Quit"
             << "\n\tEnter 1 - 10: ";
        cin >> option;
        system("cls");

        if(option != 10)
        {
            cout << "\n\n\tEmployee ID: " << employee_id << "\t" << "Employee Name: " << full_name;

            float overtime = overtimehours * 1.5 * payrate;
            cout << "\n\n\t\tWeekly Total Hours: " << (reghours + overtimehours);
        }

        switch(option)
    {
    case 1:
    {   grosspay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, option);
        cout << "\n\n\tOption 1 - Gross Pay";
        cout << "\n\n\t\tGross Pay = (" << reghours << " regular hours times $"
             << payrate << ") plus (" << overtimehours << " overtime hours times $"
             << payrate << " times 1.5) \n\t\t= $" << grosspay;

        cout << "\n\n\t\tGross Pay: $" << grosspay;
        break;
    }
    case 2:
    {
        fedtax = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, option);
        grosspay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 1);
        cout << "\n\n\tOption 2 - Federal Taxes Withheld @ " << (fedrate*100) << "% = \t$" << fedtax;
        cout << "\n\n\tFederal Taxes Withheld = $" << grosspay << " times " << (fedrate*100) << "% = \t$" << fedtax;
        break;
    }
    case 3:
    {
        statetax = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, option);
        grosspay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 1);
        cout << "\n\n\tOption 3 - State Taxes Withheld @ " << (staterate*100) << "% = \t$" << statetax;
        cout << "\n\n\tState Taxes Withheld = $" << grosspay << " times " << (staterate*100) << "% = \t$" << statetax;
        break;
    }
    case 4:
    {
        medicare = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, option);
        grosspay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 1);
        cout << "\n\n\tOption 4 - Medicare Taxes Withheld $" << medicare;
        cout << "\n\n\tMedicare Taxes Withheld = $" << grosspay << " times 1.45% = $" << medicare;
        break;
    }
    case 5:
    {
        socials = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, option);
        grosspay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 1);
        cout << "\n\n\tOption 5 - Social Security Taxes Withheld \t$" << socials;
        cout << "\n\n\tSocial Security Taxes Withheld = $" << grosspay << " times 6.2% = $" << socials;
        break;
    }
    case 6:
    {
        netpay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, option);
        cout << "\n\n\tOption 8 - Net Pay = $" << netpay;
        break;
    }
    case 7:
    {
        regpay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, option);
        cout << "\n\n\tOption 7 - Regular Pay";
        cout << "\n\n\t\tRegular Pay: " << reghours << " hours @ $" << payrate << " = " << regpay;
        break;
    }
    case 8:
    {
        overtime = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, option);
        cout << "\n\n\tOption 8 - OverTime Pay";
        cout << "\n\n\t\tOvertime Pay: " << overtimehours << " hours @ 1.5 times $" << payrate << " = " << overtime;

        break;
    }
    case 9:
    {

        grosspay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 1);
        fedtax = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 2);
        statetax = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 3);
        medicare = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 4);
        socials = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 5);
        netpay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 6);
        regpay = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 7);
        overtime = payrollcalculations(reghours, overtimehours, payrate, fedrate, staterate, 8);

        cout << "\n\n\tOption 9 - All Payroll Calculations";

        cout << "\n\n\tGross Pay: $" << grosspay;
        cout << "\n\n\tFederal Taxes Withheld @ " << fedrate*100 << "% = $" << fedtax;
        cout << "\n\n\tState Taxes Withheld @ " << staterate*100 << "% = $" << statetax;
        cout << "\n\n\tMedicare Taxes Withheld = $" << medicare;
        cout << "\n\n\tSocial Security Taxes Withheld = $" << socials;
        cout << "\n\n\tNet Pay = $" << netpay;
        cout << "\n\n\tRegular Pay: " << reghours << " hours @ $" << payrate << " = " << regpay;
        cout << "\n\n\tOvertime Pay: " << overtimehours << " hours @ 1.5 times $" << payrate << " = " << overtime;
    }

    }


        if (option == 10)
        {
             cout << "\n\tEnding Program";
             again = 'n';
        }
        else
        {
            cout << "\n\n\tAnother option for Employee Name: " << full_name << "? (y or n):\n\t";
            cin >> again;
            again = tolower(again);
            system("cls");
            cin.clear();
            cin.ignore(10,'\n');
        }

    }

    cout << "\n\n\tRun this Exercise Again (y or n):\n\t";
    cin >> again;
    again = tolower(again);
    system("cls");
    cin.clear();
    cin.ignore(10,'\n');

    }
}

float filter(float minimum, float maximum, float input)
{
    while(input < minimum || input > maximum)
    {
        cout << "\n\tYou have entered an input that's not between " << minimum << " and " << maximum << "."
             << "\n\tPlease enter a valid input between the interval: ";
        cin >> input;

    }
    return input;
}

float payrollcalculations(float reghours, float overtimehours, float payrate, float fedrate, float staterate, int option)
{

    //Calculations
    float regpay = payrate * reghours;
    float overtime = overtimehours * 1.5 * payrate;
    float grosspay = regpay + overtime;
    float fedtax = fedrate * grosspay;
    float statetax = staterate * grosspay;
    float socials = grosspay * 0.0620;
    float medicare = grosspay * 0.0145;
    float netpay = grosspay - fedtax - statetax - socials - medicare;

    switch(option)
    {
    case 1:
    {
        return grosspay;
        break;
    }
    case 2:
    {
        return fedtax;
        break;
    }
    case 3:
    {
        return statetax;
        break;
    }
    case 4:
    {
        return medicare;
        break;
    }
    case 5:
    {
        return socials;
        break;
    }
    case 6:
    {
        return netpay;
        break;
    }
    case 7:
    {
        return regpay;
        break;
    }
    case 8:
    {
        return overtime;
        break;
    }

    }
}
