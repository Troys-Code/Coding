#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>
#include<fstream>

using namespace std;

class information
{
    //private:
    string ID = "N\A";
    string LastName;
    string FirstName;
    float GPA;
    int EnrolledClasses;

    public:

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
    string GetID()
    {
        return ID;
    }
    string GetLastName()
    {
        return LastName;
    }
    string GetFirstName()
    {
        return FirstName;
    }
    float GetGPA()
    {
        return GPA;
    }
    float GetClasses()
    {
        return EnrolledClasses;
    }
    void DisplayStudent()
    {
        cout << "\n\n\tStudent ID: " << ID
             << "\n\t" << LastName << ", " << FirstName
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

void transfer(information []);
void transfer(information workers[])
{
    int count = 0;
    string word, last, first;
    float gpa;
    int classes;
    ifstream inputFile;
    inputFile.open("Students.dat");

    inputFile >> word >> last >> first;
    inputFile >> gpa >> classes;
    workers[count].SetAll(word, last, first, classes, gpa);

    while(!inputFile.eof())
    {
        count++;
        inputFile >> word >> last >> first;
        inputFile >> gpa >> classes;
        workers[count].SetAll(word, last, first, classes, gpa);
    }
    inputFile.close();
}

int DataSize();
int DataSize()
{
    int count = 0;
    string word1, word2, word3;
    float num1;
    int num2;

    ifstream inputFile;
    inputFile.open("Students.dat");

    inputFile >> word1 >> word2 >> word3;
    inputFile >> num1 >> num2;

    while(!inputFile.eof())
    {
        count++;
        inputFile >> word1 >> word2 >> word3;
        inputFile >> num1 >> num2;
    }
    inputFile.close();
    return count;

}

int main()
{
    char again = 'y';
    int option;
    int extra = 20 - DataSize();
    int width = DataSize();

    information student[20];
    transfer(student);

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    while(again == 'y')
    {
        do
        {
            cout << "\n\tMenu: "
                 << "\n\n\t1 - Display ALL Records"
                 << "\n\t2 - Add a New Record to the Maximum of " << extra << " Records"
                 << "\n\t3 - Change an Existing Record's Fields"
                 << "\n\t4 - Find a Record"
                 << "\n\t5 - Quit (Must Quit in Order to Save Data and Changes)";

            cout << "\n\n\tEnter Option: ";
            cin >> option;
            system("cls");
        }while(option < 1 || option > 5);

        switch(option)
        {
            case 1:
            {
                cout << "\n\tOption 1 - Displaying All Records";
                for(int n = 0; n < width; n++)
                {
                    student[n].DisplayStudent();
                }
                break;
            }
            case 2:
            {
                cout << "\n\tOption 2 - Adding a New Record";
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

                    cout << "\n\t(5 of 5) Enter the new Student's GPA: ";
                    cin >> gpa;

                    student[width].SetAll(id, Last, First, enrolledclasses, gpa);
                    cout << "\n\t";
                    student[width].DisplayStudent();
                    width++;
                    extra--;
                }
                else
                {
                    cout << "\n\tUnable to add more students to the record";
                }
                break;
            }
            case 3:
            {
                int choice;
                do
                {
                    system("cls");
                    cout << "\n\tOption 3: Change an Existing Record's Fields"
                         << "\n\n\tSelect Array Index #0 - " << width-1 << ": ";
                    cin >> choice;
                }while(choice < 0 || choice > width-1);
                system("cls");

                while(again == 'y')
                {
                    string words;
                    int number, temp;
                    float decimal;
                    do
                    {
                        system("cls");
                        student[choice].DisplayStudent();
                        cout << "\n\n\tArray Index #" << choice
                             << "\n\t1 - Set New ID"
                             << "\n\t2 - Set New Last Name"
                             << "\n\t3 - Set New First Name"
                             << "\n\t4 - Set New Number of Classes Enrolled"
                             << "\n\t5 - Set New GPA"
                             << "\n\t6 - Set All"
                             << "\n\t7 - Return to Original Menu";
                        cout << "\n\n\tEnter An Option: ";
                        cin >> temp;
                        cin.ignore();
                        cin.clear();
                    }while(temp < 1 || temp > 7);

                    switch(temp)
                    {
                        case 1:
                        {
                            cout << "\n\n\tEnter New ID: ";
                            getline(cin, words);
                            student[choice].setID(words);
                            break;
                        }
                        case 2:
                        {
                            cout << "\n\n\tEnter New Last Name: ";
                            getline(cin, words);
                            student[choice].setLast(words);
                            break;
                        }
                        case 3:
                        {
                            cout << "\n\n\tEnter New First Name: ";
                            getline(cin, words);
                            student[choice].setFirst(words);
                            break;
                        }
                        case 4:
                        {
                            cout << "\n\n\tEnter New Number of Classes Enrolled: ";
                            cin >> number;
                            student[choice].SetClasses(number);
                            break;
                        }
                        case 5:
                        {
                            cout << "\n\n\tEnter New GPA: ";
                            cin >> decimal;
                            student[choice].setGPA(decimal);
                            break;
                        }
                        case 6:
                        {
                            system("cls");
                            string id, Last, First;
                            float gpa;
                            int enrolledclasses;

                            cout << "\n\tOption 6 - Rewriting Index Array #" << choice << "\'s Data";
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

                            cout << "\n\t(5 of 5) Enter the new Student's GPA: ";
                            cin >> gpa;

                            student[choice].SetAll(id, Last, First, enrolledclasses, gpa);
                            break;
                        }
                        case 7:
                        {
                            again = 'n';
                            break;
                        }
                    }
                    if(temp != 7)
                    {
                    cout << "\n\tHit Any Key to Continue...";
                    getch();
                    system("cls");
                    }
                }

            cout << "\n\tReturning to Original Menu";
            again = 'y';
            break;
            }
            case 4:
            {
                while(again == 'y')
                {
                    do
                    {
                        system("cls");
                        cout << "\n\tOption 4 - Find a Record";
                        cout << "\n\n\tEnter an Array Index from 0 to " << width-1 << ": ";

                        cin >> option;
                    }while(option < 0 || option > width-1);

                    student[option].DisplayStudent();

                    cout << "\n\n\tFind another Record? (y or n)";
                    cout << "\n\tEnter Option: ";
                    cin >> again;
                    again = tolower(again);
                }

                cout << "\n\tReturning to Original Menu";
                again = 'y';
                break;
            }
            case 5:
            {
                cout << "\n\tOption 5:"
                     << "\n\tQuitting...";
                again = 'n';
                break;
            }
        }

        cout << "\n\n\tHit Any Key to Continue...";
        getch();
        system("cls");
    }
    ofstream outputFile;
    outputFile.open("Students.dat" , ios::out);

    for(int n = 0; n < 20-extra; n++)
    {
        outputFile << student[n].getID() << " " << student[n].GetLastName() << " " << student[n].GetFirstName();
        outputFile << " " << student[n].GetGPA() << " " << student[n].GetClasses() << "\n";
    }
    outputFile.close();
}
