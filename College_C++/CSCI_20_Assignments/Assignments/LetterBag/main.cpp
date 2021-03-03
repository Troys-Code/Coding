#include <iostream>
#include "LetterBag.h"
#include <string>

using namespace std;

int main()
{
    LetterBag bag1;
    bag1+= 'a';
    bag1+= 'a';
    bag1+= 'b';
    bag1+= 'c';


    cout << bag1 << endl;

    LetterBag bag2;
    bag2 = bag1.makeSet(); // return new set and assign it to that

    cout << bag2;
//    char YesOrNo = 'y';
//    bool display = false;
//
//    cout << "Desplay Test Cases? Y or N?";
//    cin >> YesOrNo;
//    if(tolower(YesOrNo)== 'y')
//        display = true;
//
//    LetterBag bag1;
//    cout << "This is The Test Program\n\n"
//         << "Please Enter All The Letters To Add Into The LetterBag bag1,Then Press Enter\n"
//         << "(bag2 will contain letters 'adfqssw' use this to test == operator)\n" << endl;
//
//    cin >> bag1;
//    if(display)
//        cout << "\n" << bag1 << "\t\t\t";
//
//    cout << "\n\n-Tested Blank Constructor(created empty bag)\n\n"
//         << "-Tested Operator Overload >> (with cin)\n\n"
//         << "-Tested Operator Overload << (with cout)\n" << endl;
//
//    LetterBag bag2("adfqssw");
//
//    if(display)
//        cout << "\n\nbag1: " << bag1 << "\tbag2: " << bag2 << "\n\t\t\t";
//
//    if(display)
//        if(bag1==bag2)
//            cout << "\nYes bag1 and bag2 Contain Equal Contents\n\n\t\t\t";
//        else
//            cout << "\nNO! bag1 and bag2 Do Not Contain Equal Contents\n\n\t\t\t";
//
//    cout << "-Tested OverLoaded Operator == Comparing the contents in bag1 to bag2: if(bag1==bag2)\n" << endl;
//
//    if(display)
//        if(bag1!=bag2)
//            cout << "Yes bag1 and bag2 Contain Equal Contents\n\t\t\t";
//        else
//            cout << "NO! bag1 and bag2 Do Not Contain Equal Contents\n\t\t\t";
//
//    cout << "-Tested OverLoaded Operator != Comparing the contents in bag1 to bag2: if(bag1!=bag2)\n" << endl;
//
//
//    string Letters;
//    if(display)
//        cout << bag2 << "\t\t\t";
//    cout << "-Tested Parameterized Constructor To Create A Second LetterBag Bag2: LetterBag bag2( adfqssw )\n\n";
//    if(display)
//         cout << bag2.getFrequency('S') << "\t\t\t";
//    cout << "-Tested getFrequency() To Get a Character Count of 's'\n\n";
//
//    if(display)
//        cout<< bag2.getCurrentSize() << "\t\t\t";
//    cout << "-Tested getCurrentSize() to return number of characters in bag2\n" << endl;
//
//    Letters = bag2.toString();
//    if(display)
//        cout << Letters << "\t\t\t";
//    cout << "-Tested toString() Function to Display The Letters Added To Bag2 in Alphabetic Order / Lexicographic order\n" << endl;
//
//    bag2+='L';
//    if(display)
//        cout << bag2 << "\t\t";
//    cout << "-Tested the overloaded opperator += Added character 'L' to bag2\n" << endl;
//
//    bag2.removeAll('L');
//    bag2.removeAll('S');
//    if(display)
//        cout << bag2 << "\t\t\t";
//
//    cout << "-Tested Removing Removed all characters 'L' and S' from bag2\n" << endl;
//
//    bag2.clear();
//    if(display)
//        cout <<"\"" << bag2 << "\"" << "\t\t\t Bag2 Has Been Cleared Of All Elements";
//
//    cout << "-Tested Clearing bag2 Under The Hood Displaying Cleared / Emptied Bag2\n\n";
//
//    LetterBag bag3 = bag1+'L';
//    if(display)
//        cout << "\nBag3 = (Bag1: " << bag1 << ") + (char: 'L') // bag1+'L'\n\n" << bag3 << "\t\t";
//
//    cout << "-Tested = opperator and + opperator together\n\n\n"
//         << "End Of Test Driven Design Coded Application\n\n"
//         << "If You Find Bugs\n"
//         << "Feel Free To Report Them and they will be removed Asap\n"
//         << "Thank You." << endl;
//    system("pause");

//    LetterBag bag1("ABCDEFGhijklmnopqrstuvwxyz");
//    cout << bag1 << "\t" << bag1.getCurrentSize() << endl;
//    bag1.clear();
//    cout << bag1 << "Cleared\t" << bag1.getCurrentSize() << endl;
    return 0;
}

