#include <stdlib.h>
#include <conio.h>
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

using namespace std;

int main()
{
    char again = 'y';

    string sentence;
    int a, e, i, o, u, nonvowels, characters;

    while(again == 'y')
    {
        a = e = i = o = u = nonvowels = 0;

        cout << "\n\tEnter a string of text: ";
        getline(cin, sentence);
        cin.clear();
        characters = sentence.length();

        cout << "\n\n\tThere are " << characters << " characters in \"" << sentence << "\"";

        for(int n = 0; n < characters; n++)
        {
            char temp;
            temp = sentence[n];
            temp = tolower(temp);

            switch(temp)
            {
            case 'a':
                {
                a++;
                break;
                }
            case 'e':
                {
                e++;
                break;
                }
            case 'i':
                {
                i++;
                break;
                }
            case 'o':
                {
                o++;
                break;
                }
            case 'u':
                {
                u++;
                break;
                }
            default:
                {
                nonvowels++;
                break;
                }
            }
        }

        cout << "\n\n\t\"" << sentence << "\" has: "
             << "\n\t" << a << " A's"
             << "\n\t" << e << " E's"
             << "\n\t" << i << " I's"
             << "\n\t" << o << " O's"
             << "\n\t" << u << " U's"
             << "\n\t" << nonvowels << " non vowels (including blanks)";

        cout << "\n\n\tRun this Again (y or n):\n\t";
        cin >> again;
        again = tolower(again);
        cin.clear();
        cin.ignore();
        system("cls");
    }

}
