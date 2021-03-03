#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

class Vehicles
{
    protected:
    string vehiclename;
    int passengers;
    int wheels;
    float mph;

    public:
    //sets variables
    void setname(string name)
    {
        vehiclename = name;
    }
    void setpassengers(int number)
    {
        passengers = number;
    }
    void setwheels(int tires)
    {
        wheels = tires;
    }
    void setmph(float maxspeed)
    {
        mph = maxspeed;
    }

    //returns varibles
    string getname()
    {
        return vehiclename;
    }
    int getpassengers()
    {
        return passengers;
    }
    int getwheels()
    {
        return wheels;
    }
    float getmph()
    {
        return mph;
    }

    //constructor
    Vehicles()
    {
        vehiclename = "Motorcycle";
        passengers = 2;
        wheels = 2;
        mph = 100;
    }
};

class Trucks : public Vehicles
{
    private:
    float load;
    float weight;

    public:
    void setload(float maxcarry)
    {
        load = maxcarry;
    }
    void setweight(float body)
    {
        weight = body;
    }
    float getload()
    {
        return load;
    }
    float getweight()
    {
        return weight;
    }
    Trucks()
    {
        vehiclename = "Truck";
        load = 0;
        weight = 2000;
    }
};

//regular functions
void DisplayAll(Vehicles stuff[], int n)
{
    cout << "\n\n\tIndex# " << n;
    cout << "\n\t" << stuff[n].getname() << " carries " << stuff[n].getpassengers()
         << " passengers (Including the Driver)"
         << "\n\t" << stuff[n].getname() << " has " << stuff[n].getwheels()
         << " wheels and can travel a maximum of " << stuff[n].getmph() << " mph.";
}
void DisplayAll(Trucks stuff[], int n)
{
    cout << "\n\n\tIndex# " << n;
    cout << "\n\t" << stuff[n].getname() << " carries " << stuff[n].getpassengers()
         << " passengers (Including the Driver)"
         << "\n\t" << stuff[n].getname() << " has " << stuff[n].getwheels()
         << " wheels and can travel a maximum of " << stuff[n].getmph() << " mph.";
}
int main()
{

    char again = 'y';
    int width, option;

    //switch variables
    int temp, value, vehiclecount = 0, truckcount = 0;
    float digit;
    string words;
    Trucks OptimusPrime[2];
    //line 134 Declared Vehicles HotRods[width]

    /*
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);
    */

    do
    {
        cout << "\n\tEnter the amount of Vehicles you would like to have in the array (Cannot be 0): ";
        cin >> width;
        system("cls");
    }while(width <= 0);

    cout << "\n\t(Vehicle array of " << width << ") and (array of 2 Trucks) have been made.";
    cout << "\n\tHit Any Key to Continue...";
    getch();
    system("cls");

    Vehicles HotRods [width];

    while(again == 'y')
    {
        do
        {
        cout << "\n\tMenu:"
             << "\n\t1 - Display All Vehicles"
             << "\n\t2 - Change Values of a Class Member"
             << "\n\t3 - Find a Vehicle Class Member"
             << "\n\t4 - Add a new Vehicle or Truck"
             << "\n\t5 - Display Truck Values"
             << "\n\t6 - Change Truck Members"
             << "\n\t7 - Quit"
             << "\n\n\tEnter an Option: ";

        cin >> option;
        system("cls");
        } while(option < 1 || option > 7);

        switch(option)
        {
            case 1:
            {
                cout << "\n\tOption 1 - Display All Vehicles";
                for(int n = 0; n < width; n++)
                {
                    DisplayAll(HotRods, n);
                }
                break;
            }
            case 2:
            {
                do
                {
                    cout << "\n\tOption 2 - Change Values of a Vehicle";
                    cout << "\n\n\tEnter an Index between 0 - " << width-1 << ": ";
                    cin >> option;
                }while(option < 0 || option > width-1);

                while (again == 'y')
                {
                    do
                    {
                        DisplayAll(HotRods, option);

                        cout << "\n\n\t1 - Change the Name of Index #" << option
                             << "\n\t2 - Change number of Passengers (Including the Driver)"
                             << "\n\t3 - Change number of Wheels"
                             << "\n\t4 - Change Max Speed (mph)"
                             << "\n\t5 - Change All Information"
                             << "\n\t6 - Quit";

                        cout << "\n\n\tEnter an Option: ";
                        cin >> temp;
                        cin.clear();
                        cin.ignore();
                        system("cls");
                    }while(temp < 1 || option > 5);

                    switch(temp)
                    {
                        case 5:
                            cout << "Changing All Information";
                        case 1:
                        {
                            cout << "\n\t1 - Change the Name of Index #" << option;
                            cout << "\n\n\tEnter New Name: ";
                            getline(cin, words);
                            cin.clear();
                            HotRods[option].setname(words);

                            if(temp != 5)
                            {
                                break;
                            }
                        }
                        case 2:
                        {
                            cout << "\n\t2 - Change number of Passengers (Including the Driver)";
                            cout << "\n\n\tEnter the new number of Passengers (Including the Driver): ";
                            cin >> value;
                            HotRods[option].setpassengers(value);

                            if(temp != 5)
                            {
                                break;
                            }
                        }
                        case 3:
                        {
                            cout << "\n\t3 - Change number of Wheels";
                            cout << "\n\n\tEnter the new number of Wheels: ";
                            cin >> value;
                            HotRods[option].setwheels(value);

                            if(temp != 5)
                            {
                                break;
                            }
                        }
                        case 4:
                        {
                            cout << "\n\t4 - Change Max Speed (mph)";
                            cout << "\n\n\tEnter the new Max Speed (mph): ";
                            cin >> digit;
                            HotRods[option].setmph(digit);

                            if(temp != 5)
                            {
                                break;
                            }
                        }
                        case 6:
                        {
                            cout << "\n\tOption 6:"
                                 << "\n\tQuitting...";
                            again = 'n';
                            break;
                        }
                    }
                system("cls");
                }
                again = 'y';
                break;
            }
            case 3:
            {
                cout << "\n\tOption 3 - Find a Vehicle Class Member";
                do
                {
                    cout << "\n\n\t1 - Find Vehicle based on Index #";
                    cout << "\n\t2 - Find Vehicle based on Name";
                    cout << "\n\n\tEnter an Option: ";
                    cin >> option;
                    cin.clear();
                    cin.ignore();
                    system("cls");
                }while(option < 0 || option > 2);

                switch(option)
                {
                    case 1:
                    {
                        do
                        {
                            cout << "\n\t1 - Find Vehicle based on Index #";
                            cout << "\n\n\tEnter an Index between #0 - #" << width-1 << ": ";
                            cin >> option;
                        }while(option < 0 || option > width-1);

                        DisplayAll(HotRods, option);
                        break;
                    }
                    case 2:
                    {
                        cout << "\n\t2- Find Vehicle based on Name";
                        cout << "\n\n\tEnter Vehicle Name: (Case and Spacing Sensitive): ";
                        getline(cin, words);
                        cin.clear();

                        bool choice = false;
                        for(int n = 0; n < width; n++)
                        {
                            if(HotRods[n].getname() == words)
                            {
                                DisplayAll(HotRods, n);
                                choice = true;
                            }
                        }
                        if(choice ==  false)
                        {
                            cout << "\n\tUnable to Find a Vehicle with a name of: " << words;
                        }
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                do
                {
                    cout << "\n\tOption 4 - Add a New:";
                    cout << "\n\n\t1 - Vehicle"
                         << "\n\t2 - Truck";
                    cout << "\n\n\tEnter an Option: ";
                    cin >> option;
                    cin.clear();
                    cin.ignore();
                    system("cls");
                }while(option < 1 || option > 2);

                switch(option)
                {
                    case 1:
                    {
                        if(vehiclecount != width)
                        {
                            cout << "\n\tAdding new Vehicle:";

                            cout << "\n\n\t(1 of 4) Enter Vehicle Name: ";
                            getline(cin, words);
                            cin.clear();
                            HotRods[vehiclecount].setname(words);

                            cout << "\t(2 of 4) Enter Number of Passengers: ";
                            cin >> value;
                            HotRods[vehiclecount].setpassengers(value);

                            cout << "\n\t(3 of 4) Enter Number of Wheels: ";
                            cin >> value;
                            HotRods[vehiclecount].setwheels(value);

                            cout << "\n\t(4 of 4) Enter Max Speed (mph): ";
                            cin >> digit;
                            HotRods[vehiclecount].setmph(digit);

                            DisplayAll(HotRods,vehiclecount);
                            vehiclecount++;
                        }
                        else
                        {
                            cout << "Unable to add new Vehicles to the Array";
                        }

                        break;
                    }
                    case 2:
                    {
                        if(truckcount != width)
                        {
                            cout << "\n\tAdding new Truck:";

                            cout << "\n\n\t(1 of 6) Enter Truck Name: ";
                            getline(cin, words);
                            cin.clear();
                            OptimusPrime[truckcount].setname(words);

                            cout << "\n\t(2 of 6) Enter Number of Passengers: ";
                            cin >> value;
                            OptimusPrime[truckcount].setpassengers(value);

                            cout << "\n\t(3 of 6) Set the Weight of the Pickup: ";
                            cin >> digit;
                            OptimusPrime[truckcount].setweight(digit);

                            cout << "\n\t(4 of 6) Set the Maximum Load of the Pickup: ";
                            cin >> digit;
                            OptimusPrime[truckcount].setload(digit);

                            cout << "\n\t(5 of 6) Enter Number of Wheels: ";
                            cin >> value;
                            OptimusPrime[truckcount].setwheels(value);

                            cout << "\n\t(6 of 6) Enter Max Speed (mph): ";
                            cin >> digit;
                            OptimusPrime[truckcount].setmph(digit);

                            DisplayAll(OptimusPrime,truckcount);
                            truckcount++;
                        }
                        else
                        {
                            cout << "Unable to add new Vehicles to the Array";
                        }
                        break;
                    }
                }
                break;
            }
            case 5:
            {
                for(int n = 0; n < 2; n++)
                {
                    DisplayAll(OptimusPrime, n);
                    cout << "\n\t" << OptimusPrime[n].getname() << " weighs " << OptimusPrime[n].getweight()
                         << " pounds and carries a load of " << OptimusPrime[n].getload() << " pounds";
                }
                break;
            }
            case 6:
            {
                do
                {
                    cout << "\n\tOption 6 - Change Values of a Truck";
                    cout << "\n\n\tEnter an Index of 0 or 1: ";
                    cin >> option;
                }while(option < 0 || option > 1);

                while (again == 'y')
                {
                    do
                    {
                        DisplayAll(OptimusPrime, option);

                        cout << "\n\n\t1 - Change the Name of Index #" << option
                             << "\n\t2 - Change number of Passengers (Including the Driver)"
                             << "\n\t3 - Change number of Wheels"
                             << "\n\t4 - Change Max Speed (mph)"
                             << "\n\t5 - Change Weight"
                             << "\n\t6 - Change Load"
                             << "\n\t7 - Change All Information"
                             << "\n\t8 - Quit";

                        cout << "\n\n\tEnter an Option: ";
                        cin >> temp;
                        cin.clear();
                        cin.ignore();
                        system("cls");
                    }while(temp < 1 || option > 8);

                    switch(temp)
                    {
                        case 7:
                            cout << "Changing All Information";
                        case 1:
                        {
                            cout << "\n\t1 - Change the Name of Index #" << option;
                            cout << "\n\n\tEnter New Name: ";
                            getline(cin, words);
                            cin.clear();
                            OptimusPrime[option].setname(words);

                            if(temp != 7)
                            {
                                break;
                            }
                        }
                        case 2:
                        {
                            cout << "\n\t2 - Change number of Passengers (Including the Driver)";
                            cout << "\n\n\tEnter the new number of Passengers (Including the Driver): ";
                            cin >> value;
                            OptimusPrime[option].setpassengers(value);

                            if(temp != 7)
                            {
                                break;
                            }
                        }
                        case 3:
                        {
                            cout << "\n\t3 - Change number of Wheels";
                            cout << "\n\n\tEnter the new number of Wheels: ";
                            cin >> value;
                            OptimusPrime[option].setwheels(value);

                            if(temp != 7)
                            {
                                break;
                            }
                        }
                        case 4:
                        {
                            cout << "\n\t4 - Change Max Speed (mph)";
                            cout << "\n\n\tEnter the new Max Speed (mph): ";
                            cin >> digit;
                            OptimusPrime[option].setmph(digit);

                            if(temp != 7)
                            {
                                break;
                            }
                        }
                        case 5:
                        {
                            cout << "\n\t5 - Change Weight";
                            cout << "\n\n\tEnter New Weight: ";
                            cin >> digit;
                            OptimusPrime[option].setweight(digit);

                            if(temp != 7)
                            {
                                break;
                            }
                        }
                        case 6:
                        {
                            cout << "\n\t6 - Change Load";
                            cout << "\n\n\tEnter New Max Load: ";
                            cin >> digit;
                            OptimusPrime[option].setweight(digit);

                            if(temp != 7)
                            {
                                break;
                            }
                        }
                        case 8:
                        {
                            cout << "\n\tOption 6:"
                                 << "\n\tQuitting...";
                            again = 'n';
                            break;
                        }
                    }
                system("cls");
                }
                again = 'y';
                break;
            }
            case 7:
            {
                cout << "\n\tOption 7:"
                     << "\n\tQuitting...";
                again = 'n';
                break;
            }
        }
        cout << "\n\n\tHit Any Key to Continue...";
        getch();
        system("cls");
    }
}
