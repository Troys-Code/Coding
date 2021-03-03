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
    string sentence;
    string tempsentence;

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

                cout << "\n\n\tThe target string to be translated is: \n\t" << sentence;

                int numchars = sentence.length();
                cout << "\n\n\tNumber of characters in the string is "  << numchars;

                //Capitalizes all letters in the string.
                for(int n = 0; n < numchars; n++)
                {
                    sentence[n] = toupper(sentence[n]);
                }

                string output[numchars+1];
                string temp;

                for(int n = 0; n < numchars; n++)
                {
                    temp = sentence[n];

                    for(int a = 0; a < 39; a++)
                    {
                        if( temp == alphabet[a])
                        {
                            output[n] = morsecode[a];
                        }
                    }
                        if(temp == " ")
                        {
                            output[n] = " ";
                        }
                        if(n == numchars)
                        {
                            output[n+1] = morsecode[36];
                        }
                }


                cout << "\n\n\tIn Morse the message is:\n\t";
                for(int n = 0; n < numchars+1; n++)
                {
                   cout << output[n] << " ";

                   if(output[n] == " ")
                   {
                       cout << "\n\t";
                   }
                }
                cout << " (END of Message)";

                cout << "\n\tHit Any Key To Continue";
                getch();

                break;
            }
        //Decode
        case 2:
            {
                break;
            }
        //Display Morse Code
        case 3:
            {
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
                cout << "\n\tYou have entered an invalid option, please enter a valid option.";
                cout << "\n\tHit Any Key To Continue";
                getch();
                break;
            }

    }

        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        system("cls");
    if(again == 'n')
    {
        cout << "\n\tEnding Program";
    }

    }


}
