#include "LetterBag.h"
using namespace std;

LetterBag::LetterBag(){ int LetterCount[26] = {0};}                             // Dead Code I Do Not Need It Because Initialized to all 0 On creation in Header File

/// Use a string to initialize the object. Non letters are skipped. Also, case is ignored, e.g. "ababa" and "ABABA" both mean "three a's and two b's"
LetterBag::LetterBag(const string &s)
{
    char ch;
    for(char const &c: s)                                                       // Range For Loop: assigns each element of the string to c till the end of the string
    {
        ch = tolower(c);                                                        // ch Holds The Lowercase value of c(Handles Capitals)
        if(ch >= 'a' && ch <= 'z')                                              // If ch is in the range of a-z
            LetterCount[ch - 'a']++;                                            // (ch's asci value) - 97 = the correct index number. example: z-a = 122-97 = 25
    }
}

/// return the total number of letters
int LetterBag::getCurrentSize() const
{
    int total = 0;
    for(int i = 0; i < 26; i++)
        total += LetterCount[i];                                                // Add The amount of chars held in the int array to the total (for all letters in array)
    return(total);
}

/// remove all occurences, occurrence of char from the current object. If char is out of range or has count equal to zero do nothing.
void LetterBag::removeAll(char ch)
{
    ch = tolower(ch);
    if(ch >= 'a' && ch <= 'z')                                                  // If Char Is Within Range (Prevents Index Out Of Bounds = 0)
        LetterCount[ch - 'a'] = 0;                                              // char a - 'a' = 97-97 = 0 LetterCount[0] which is 'a', char z - 'a' = 122-97 = 25 LetterCount[25] which is z
}

/// remove all occurrences of all letters.
void LetterBag::clear()
{
    for(int i = 0; i < 26; LetterCount[i++] = 0);
}

/// return the number of occurence of char in the current object.
int LetterBag::getFrequency(char ch) const
{   ch = towlower(ch);
    if( ch >= 'a' && ch <= 'z')                                                 // If In Range
        return(LetterCount[ch - 'a']);                                          // Return Number Of Char
    else
        return(0);                                                              // Out Of Range Return 0
}

/// return a string with the letters in this object, in sorted order and lowercase. e.g. "ddfz"
string LetterBag::toString() const
{
    string temp;
    for(int i = 0; i < 26; i++)                                                 // Run Through All 26 Letters Of LetterCount Array
        for(int j = 0; j < LetterCount[i]; j++)                                 // Runs How Ever Many Letters There Are At Index [i] Times
            temp += (i + 'a');                                                  // Add Character to string: 'a' + 25 = 'z', ascii 97 + 25 = 122 = 'z'
    return(temp);                                                               // Return string compiled
}

/// insert char into the current object and return the current object if ch is out of range, do nothing.
LetterBag& LetterBag::operator+=(char ch)
{
    ch = tolower(ch);
    if( ch >= 'a' && ch <= 'z')                                                 // If within range
        LetterCount[ch - 'a']++;                                                // Add Another character To The Count Array
    return(*this);                                                              // Return This LetterBag Object
}

///insert char into a copy of the current object and return the copy. If char is out of range, do nothing. 'A' and 'a' both LetterCount as an 'a' etc.
LetterBag LetterBag::operator+(char ch) const
{
    LetterBag temp = *this;                                                     // Copied The Current Objects LetterBag into temp LetterBag
    return(temp+=ch);                                                           // Here We Return temp while using overloaded += to add the character in
}                                                                               // NOTE: When You Return An Object It Is Destroyed When It Leaves Scope

/// return true if the current object and other are equal.
bool LetterBag::operator==(const LetterBag &other) const
{
    return(this->toString() == other.toString());                               // Using Default == from the string library, cause why not its comparing 2 strings
}

/// return false if the current object and other are equal.
bool LetterBag::operator!=(const LetterBag &other) const
{
    return(this->toString() != other.toString());                               // Using Default != from the string library for the same reason as ==
}

/// output from the LetterBag object to the output stream, which letters in sorted order e.g. { d, d, f, z }
ostream& operator<<(ostream &out, const LetterBag &let)
{
    out << let.toString();                                                      // Letters in sorted order inserted into the output stream (to be used by cout an output stream)
    return(out);
}

/// input Object contents into the LetterBag from the input stream
istream& operator>>(istream &in, LetterBag &let)                                //cin characters >> Add All characters from a string into the bag insert in let; return letterbag
{
    string userInputString;                                                     // Create A String To Hold The User Input
    in >> userInputString;                                                      // Insert Parameter InStream
    LetterBag temp(userInputString);                                            // Create A temp Letter Bag With User Input String
    let = temp;                                                                 // Copy temp Into &let To Change Its Value Outside The Function
    return(in);
}

// Make a letter bag
LetterBag LetterBag::makeSet()
{
    LetterBag FreshBag;
    for(int i = 0; i < 26; i++)
    {
        if(this->getFrequency(97 + i) > 0)
        {
            char temp = 97 + i;
            FreshBag += temp;
        }
    }
    return(FreshBag);
}
