#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>


using namespace std;


//Function Prototypes
float FILTER (float, float, bool); //INPUT (MAX, MIN, % or not) GARBO IN OUT
float CALC (float, float, float, float, float, float, int); // (HRS, PAY, FTAX, STAX, MEDT, SST, OPT)


int main ()
{


//Set Precision
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);


//Loop APP
    char AGAIN = 'y';


    while (AGAIN != 'n')
    {


//Variables
        string NAME, ID, IN_HRS, IN_PAY, IN_FTAX, IN_STAX;
        float HRS, PAY, FTAX, STAX, MEDT, SST;
        float HR_MIN, HR_MAX, PAY_MIN, PAY_MAX, FTAX_MIN, FTAX_MAX, STAX_MIN, STAX_MAX;
        int OPT = 0;

//Initializations
        HR_MIN = 0;
        HR_MAX = 60;
        PAY_MIN = 10.75;
        PAY_MAX = 99.99;
        FTAX_MIN = 0;
        FTAX_MAX = 50;
        STAX_MIN = 0;
        STAX_MAX = 30;
        MEDT = 1.45;
        SST = 6.2;


        OPT = 0;


//Input
        cout << "\n\t\tPayroll Calculator";


        cout << "\n\n\t1 of 6 - Enter Employee Full Name : ";
        getline (cin, NAME);


        cout << "\n\t2 of 6 - Enter Employee ID : ";
        getline (cin, ID);


        cout << "\n\t3 of 6 - Enter Employee Hours (Max 60) : ";
        HRS = FILTER (HR_MIN, HR_MAX, false);


        cout << "\n\t4 of 6 - Enter Employee Pay Per Hour ($10.75 to $99.99) : $";
        PAY = FILTER (PAY_MIN, PAY_MAX, false);


        cout << "\n\t5 of 6 - Enter Employee Federal Tax Rate (" << FTAX_MIN <<" to " << FTAX_MAX<< "% or " << FTAX_MAX/100 << ") : ";
        FTAX = FILTER (FTAX_MIN, FTAX_MAX, true);


        cout << "\n\t6 of 6 - Enter Employee State Tax Rate (" << STAX_MIN<< " to " << STAX_MAX << "% or " << STAX_MAX/100 << ") : ";
        STAX = FILTER (STAX_MIN, STAX_MAX, true);


        system ("clear");


//Loop Menu
        while (OPT != 10)
        {

//Menu
            cout << "\n\tMenu";


            cout << "\n\n\tNAME : " << NAME << "\tID : " << ID << "\t Total Weekly Hours : " << HRS;


            cout << "\n\n\t 1 - Gross Pay";
            cout << "\n\t 2 - Federal Taxes Withheld @ " << STAX << "%";
            cout << "\n\t 3 - States Taxes Withheld @ " << FTAX << "%";
            cout << "\n\t 4 - Medicare Witheld @ " << MEDT << "%";
            cout << "\n\t 5 - Social Security Withheld @ "<< SST << "%";
            cout << "\n\t 6 - Net Pay";
            cout << "\n\t 7 - Regular Pay @ $" << PAY << " Per Hour";
            cout << "\n\t 8 - Overtime Pay";
            cout << "\n\t 9 - All Payroll Calculations";
            cout << "\n\t10 - Quit";



            cout << "\n\n\tOPT : ";
            cin >> OPT;


            system ("clear");


//Output
            //Needed to retain Garbage in out of OPT
            switch (OPT)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                {
                    cout << "\n\tNAME : " << NAME << "\tID : " << ID << "\t Total Weekly Hours : " << HRS << "\n";
                    break;
                }
            }




            switch (OPT)
            {
                //Will run all cases if OPT == 9
                case 1:
                case 9:
                {
                    cout << "\n\t1 - Gross Pay @ $" << PAY << " Per Hour, Including Overtime -- $" << CALC (HRS, PAY, FTAX, STAX, MEDT, SST, 1);


                    if (OPT != 9)
                    {
                    break;
                    }
                }


                case 2:
                {
                    cout << "\n\t2 - Federal Taxes Withheld @ " << FTAX << "% ----------------- $" << CALC (HRS, PAY, FTAX, STAX, MEDT, SST, 2);


                    if (OPT != 9)
                    {
                        break;
                    }
                }


                case 3:
                {
                    cout << "\n\t3 - State Taxes Withheld @ " << STAX << "% ------------------- $" << CALC (HRS, PAY, FTAX, STAX, MEDT, SST, 3);


                    if (OPT != 9)
                    {
                        break;
                    }
                }


                case 4:
                {
                    cout << "\n\t4 - Medicare Withheld @ " << MEDT << "% ----------------------- $" << CALC (HRS, PAY, FTAX, STAX, MEDT, SST, 4);


                    if (OPT != 9)
                    {
                        break;
                    }
                }


                case 5:
                {
                    cout << "\n\t5 - Social Security Withheld @ " << SST << "% ---------------- $" << CALC (HRS, PAY, FTAX, STAX, MEDT, SST, 5);


                    if (OPT != 9)
                    {
                        break;
                    }
                }


                case 6:
                {
                    cout << "\n\t6 - Net Pay ----------------------------------------- $" << CALC (HRS, PAY, FTAX, STAX, MEDT, SST, 6);


                    if (OPT != 9)
                    {
                        break;
                    }
                }


                case 7:
                {
                    cout << "\n\t7 - Regular Pay @ $" << PAY << " Per Hour ------------------- $" << CALC (HRS, PAY, FTAX, STAX, MEDT, SST, 7);


                    if (OPT != 9)
                    {
                        break;
                    }
                }


                case 8:
                {
                    if (HRS > 40)
                    {
                        cout << "\n\t8 - Overtime Pay for " << HRS - 40 << " @ $" << PAY * 1.5 << " ----------------- $" << CALC (HRS, PAY, FTAX, STAX, MEDT, SST, 8);
                    }
                    else
                    {
                        cout << "\n\t9 - No Overtime Pay";
                    }


                    break;
                }
            }


            cout << "\n\n\tPress Any Key To Return To The Menu";


            getchar();


            system("clear");
        }


        cout << "\n\tRun Another Employee (y or n)? : ";
        cin >> AGAIN;
        cin.ignore();


        system ("clear");
    }
}

//Function Definitions
float FILTER (float A, float B, bool TF)
{
    string AA;
    double BB=0, COUNT = 0;


    do
    {
        if (COUNT > 0)
        {
            cout << B;
            cout << "\n\tINVALID ENTRY, Enter Another Value : ";
        }


        COUNT++;


        getline (cin, AA);


        BB = stod (AA);


//For Percents
        if ((TF) and (BB < 1))
        {
            BB = BB * 100;
        }
    }
    while ((BB < A) or (BB > B));


    return BB;
}



float CALC (float HOURS, float PAYRATE, float FEDERALTAX, float STATETAX, float MEDTAX, float SSTAX, int OPT)
{
//Varaibles
    float GROSS, FEDTW, STATETW, MEDW, SSW, NETPAY, REGPAY, OVERPAY;

//Calculations
    if (HOURS > 40)
    {
        OVERPAY = (HOURS - 40) * (PAYRATE * 1.5);
        REGPAY = (40 * PAYRATE);
        GROSS = REGPAY + OVERPAY;
    }
    else
    {
        GROSS = HOURS * PAYRATE;
        REGPAY = GROSS;
        OVERPAY =0;
    }


    FEDTW = GROSS * FEDERALTAX/100;
    STATETW = GROSS * STATETAX/100;
    MEDW = GROSS * MEDTAX/100;
    SSW = GROSS * SSTAX/100;
    NETPAY = GROSS - FEDTW - STATETW - MEDW - SSW;

//Output
    switch (OPT)
    {
        case 1:
        {
            return GROSS;
            break;
        }


        case 2:
        {
            return FEDTW;
            break;
        }


        case 3:
        {
            return STATETW;
            break;
        }


        case 4:
        {
            return MEDW;
            break;
        }


        case 5:
        {
            return SSW;
            break;
        }


        case 6:
        {
            return NETPAY;
            break;
        }


        case 7:
        {
            return REGPAY;
            break;
        }


        case 8:
        {
            return OVERPAY;
            break;
        }


        default:
        {
            return 0;
            break;
        }

    }
}
