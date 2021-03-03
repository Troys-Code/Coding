#include <stdlib.h>
#include <conio.h> // used for getch();
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

int main()
{

    char again = 'y';
    int option;
    int counter;

    string sentence;
    string tempsentence;
    string morsetemp;
    string morse = "- .... .  . -. -..  .-.-.-";
    //contains The End

    string output = "- .... .  . -. -..  .-.-.-";
    string output2;
    string temp;
    string temp2;

    string alphabet[39] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                           "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                           "U", "V", "W", "X", "Y", "Z",
                           "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
                           "Stop", ",", "?"};

    string morsecode[39] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                        //   "A"    "B"    "C"    "D"   "E"    "F"    "G"     "H"    "I"    "J"
                            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                        //   "K",    "L",   "M",  "N",  "O",    "P",    "Q",   "R",   "S",  "T"
                            "..-", "...-", ".--", "-..-", "-.--", "--..",
                        //   "U",    "V",   "W",   "X",    "Y",   "Z"
                            ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
                        //    "1"      "2"      "3"      "4"      "5"      "6"      "7"      "8"      "9"      "0"
                            ".-.-.-", "--..--", "..--.."};
                        //   "Stop"     ","       "?"

    while(again == 'y')
    {
    system("cls");
    cout << "\n\t1 - Encode (Text to Morse)";
    cout << "\n\t2 - Decode (Morse Code to Text)";
    cout << "\n\t3 - Display the Morse Code";
    cout << "\n\t4 - Quit";

    cout << "\n\n\tEnter 1, 2, 3 or 4: ";
    cin >> option;
    cin.ignore();

    switch(option)
    {
        //Encode
        case 1:
            {
                cout << "\n\n\tEnter a string with multiple words to encode:\n\t";
                getline(cin,sentence);

                cout << "\n\n\tThe target string to be translated is: \n\t\"";
                cout << sentence << "\"";

                int numchars = sentence.length();
                cout << "\n\n\tNumber of characters in the string is "  << numchars;

                output.clear();
                //Capitalizes all letters in the string.
                for(int n = 0; n < numchars; n++)
                {
                    sentence[n] = toupper(sentence[n]);
                }

                for(int n = 0; n < numchars; n++)
                {
                    temp = sentence[n];

                    for(int a = 0; a < 39; a++)
                    {
                        if(temp == alphabet[a])
                        {
                            output = output + morsecode[a] + " ";
                        }
                    }
                        if(temp == " ")
                        {
                            output += " ";
                        }

                }
                output = output + " " + morsecode[36] + " ";


                cout << "\n\n\tIn Morse the message is:\n\t";

                //Prints Each word under a different line
                for(int n = 0; n < output.length(); n++)
                {
                   temp = output[n];
                   cout << temp;

                   if(temp == " " && temp == temp2)
                   {
                        cout << "\n\t";
                   }
                   temp2 = temp;

                }

                cout << "(END of Message)";
                cin.clear();
                sentence.clear();
                output.clear();
                cout << "\n\tHit Any Key To Continue";
                getch();
                break;
            }
        //Decode
        case 2:
            {
                cout << "\n\n\tExample: - .... .  . -. -..  .-.-.- translates to THE END";
                cout << "\n\tEnter The Morse Code You Would Like To Translate: ";
                //cout << "\n\t Enter 1 space to seperate each letter, and two spaces to ";
                getline(cin,morse);
                //cout << morse;
                morse += " ";

                for(int n = 0; n < morse.length(); n++)
                {
                    //saves previous element
                    temp2 = temp;
                    //saves present element
                    temp = morse[n];

                    if(temp == " ")
                    {
                        for(int a = 0; a < 39; a++)
                            {
                                if (morsetemp == morsecode[a])
                                {
                                    output2 += alphabet[a];
                                    morsetemp.clear();
                                }
                            }
                    }
                    //compares previous and present if there are 2 space, add a space to the string
                    if(temp == " " && temp == temp2)
                    {
                        output2 += " ";
                    }

                    if(temp != " ")
                    {
                        morsetemp += morse[n];
                    }

                }

                cout << "\n\n\tIn the English Language, the message translates to:\n\t";
                cout << output2;
                morse.clear();
                output2.clear();
                break;
            }
        //Display Morse Code
        counter = 0;
        case 3:
            {
                system("cls");
                cout << "\n\tMorse Code is:\n\t";
                for(int n = 0; n < 39; n++)
                {
                    cout << "\"" << alphabet[n] << "\"" << setw(10) << morsecode[n] << setw(10);
                    counter++;
                    if(counter % 4 == 0)
                    {
                        cout << "\n\t";
                    }
                }

                break;
            }
        case 4:
            {
                system("cls");
                cout << "\n\tEnding Exercise.";
                break;
            }
        default:
            {
                cin.ignore();
                cin.clear();
                cout << "\n\tYou have entered an invalid option, please enter a valid option.";
                cout << "\n\tHit Any Key To Continue";
                getch();
                break;
            }

    }

        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        //system("cls");
    if(again == 'n')
    {
        cout << "\n\tEnding Program";
    }

    }


}
