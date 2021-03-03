#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

class information
{
    private:
    string ID;
    string LastName;
    string FirstName;
    float GPA;
    int EnrolledClasses;

    public:
    /*
    string setID(string);
    string setLastName(string);
    string setFirstName(string);
    float setGPA(float);
    int setClasses(int);
    void DisplayStudent();
    void SetAll;
    information;
    */

    void setID(string word)
    {
        ID = word;
    }
    void setLast(string last)
    {
        LastName = last;
    }
    void setFirst(string first)
    {
        FirstName = first;
    }
    void setGPA(float gpa)
    {
        GPA = gpa;
    }
    void SetClasses(int amount)
    {
        EnrolledClasses =  amount;
    }
    void DisplayStudent()
    {
        cout << "\n\n\tStudent ID: " << LastName << ", " << FirstName
             << "\n\t" << EnrolledClasses << " Classes Taken This Semester"
             << "\n\tCurrent GPA is " << GPA;
    }
    void SetAll(string word, string last, string first, int classes, float gpa)
    {
        ID = word;
        LastName = last;
        FirstName = first;
        EnrolledClasses = classes;
        GPA = gpa;
    }
    string getID()
    {
        return ID;
    }
    //constructor
    information()
    {
        ID = "N/A";
        LastName = "N/A";
        FirstName = "N/A";
        EnrolledClasses = 0;
        GPA = 0;
    }

};

int main()
{
    char again = 'y';
    int option;
    int extra = 2;

    information student1, student2, student3, student4, student5, student6;
    //information student[6];

    student1.SetAll("AF101", "Punch Man", "One", 1.0, 1);
    student2.SetAll("GC210", "Goku", "Son", 2.5, 2);
    student3.SetAll("BC324", "Sanchez", "Rick", 3.4, 3);
    student4.SetAll("CS382", "Da OG CodeMaster", "Des", 4.0, 5);

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    cout << "\n\tDisplaying Capabilities of Class Function (First 4) & Constructor (Last 2)";
    student1.DisplayStudent();
    student2.DisplayStudent();
    student3.DisplayStudent();
    student4.DisplayStudent();
    student5.DisplayStudent();
    student6.DisplayStudent();

    cout << "\n\n\tHit Any Key to continue...";
    getch();
    system("cls");

    while(again == 'y')
    {
        do
        {
            cout << "\n\tMenu: "
                 << "\n\n\t1 - Display All Initialized Students."
                 << "\n\t2 - Create a New Student Record (" << extra << " of 2 available)"
                 << "\n\t3 - Change a Student Record"
                 << "\n\t4 - Quit";

            cout << "\n\n\tEnter Option: ";
            cin >> option;
            system("cls");
        }while(option < 1 || option > 4);

        switch(option)
        {
            case 1:
            {
                cout << "\n\tOption 1:";

                student1.DisplayStudent();
                student2.DisplayStudent();
                student3.DisplayStudent();
                student4.DisplayStudent();

                if(extra != 2)
                {
                    if(student5.getID() != "N/A")
                    {
                        student5.DisplayStudent();
                    }
                    if(student6.getID() != "N/A")
                    {
                        student6.DisplayStudent();
                    }
                }
                break;
            }
            case 2:
            {
                cout << "\n\tOption 2:";
                cout << "\n\t" << extra << " spaces available.";
                if(extra != 0)
                {
                    string id, Last, First;
                    float gpa;
                    int enrolledclasses;

                    cout << "\n\n\t(1 of 5) Enter new Student ID: ";
                    cin >> id;
                    cin.clear();

                    cout << "\n\t(2 of 5) Enter new Student Last Name: ";
                    cin.ignore();
                    getline(cin, Last);
                    cin.clear();

                    cout << "\n\t(3 of 5) Enter new Student First Name: ";
                    getline(cin, First);
                    cin.clear();

                    cout << "\n\t(4 of 5) Enter the Number of Classes the new Student is Enrolled in: ";
                    cin >> enrolledclasses;

                    cout << "\n\n\t(5 of 5) Enter the new Student's GPA: ";
                    cin >> gpa;

                    system("cls");

                    cout << "\n\tDisplaying New Student's Information";
                    if(extra == 2)
                    {
                        extra--;
                        student5.SetAll(id, Last, First, enrolledclasses, gpa);
                        student5.DisplayStudent();
                    }
                    else
                    {
                        extra--;
                        student6.SetAll(id, Last, First, enrolledclasses, gpa);
                        student6.DisplayStudent();
                    }
                }
                else
                {
                    cout << "\n\tUnable to add more students to the record";
                }
                break;
            }
            case 3:
            {
                int temp =  6 - extra;
                while(again == 'y')
                {
                    int choice;
                    do
                    {
                        system("cls");
                        cout << "\n\tOption 3: Change a Student\'s Field"
                             << "\n\n\tSelect Students 1 - " << temp << "\n\t";
                        cin >> choice;
                        again = 'n';
                    }while(choice < 1 || choice > temp);

                system("cls");
                switch(choice)
                {
                    case 1:
                    {
                        cout << "\n\tStudent 1";
                        break;
                    }

                    case 2:
                    {
                        cout << "\n\tStudent 2";
                        break;
                    }

                    case 3:
                    {
                        cout << "\n\tStudent 3";
                        break;
                    }

                    case 4:
                    {
                        cout << "\n\tStudent 4";
                        break;
                    }

                    case 5:
                    {
                        cout << "\n\tStudent 5";
                        break;
                    }
                    case 6:
                    {
                        cout << "\n\tStudent 6";
                        break;
                    }

                }
                }

                break;
            }
            case 4:
            {
                cout << "\n\tOption 4:"
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
