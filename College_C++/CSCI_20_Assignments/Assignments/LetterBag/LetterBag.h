#ifndef LETTERBAG_H
#define LETTERBAG_H
#include <string>
#include <iostream>
using namespace std;

// A LetterBag object represents a collection of letters in the range 'a' through 'z'
// where we keep track of how many occurrences there are of each letter.
// For example the LetterBag {'a', 'a', 'c', 'd', 'd', 'd'} means two a's one c and three d's.
// Order doesn't matter so an object created by inserting 'b' then 'c' into an empty LetterBag is
// equal to an object created by inserting 'c' then b' into an empty LetterBag.

class LetterBag
{
    // output from the LetterBag object to the output stream, which letters in sorted order e.g. { d, d, f, z }
    friend ostream & operator<< (ostream & out, const LetterBag & let);

    // input to the LetterBag object from the input stream
    friend istream & operator>> (istream & in, LetterBag & let);

public:
    LetterBag() ;  // no-parameter constructor for an empty LetterBag.

    // Use a string to initialize the object. Non letters are skipped.
    // Also, case is ignored, e.g. "ababa" and "ABABA" both mean "three a's and two b's"
    LetterBag(const string & s);

    // return the total number of letters
    int getCurrentSize() const;

    // insert char into a copy of the current object and return the copy.
    // if char is out of range, do nothing. 'A' and 'a' both count as an 'a' etc.
    LetterBag operator+(char ch) const;

    // insert char into the current object and return the current object
    // if ch is out of range, do nothing.
    LetterBag& operator+=(char ch);

    void removeAll(char ch); // remove all occurences, occurrence of char from the current object.
                             // if char is out of range or has count equal to zero do nothing.

    void clear();   // remove all occurrences of all letters.

    int getFrequency(char c) const;    // return the number of occurence of char in the current object.

    string toString() const;   // return a string with the letters in this object, in sorted order and lowercase. e.g. "ddfz"                                             // REQUIRED

    bool operator==(const LetterBag & other) const; // return true if the current object and other are equal.

    bool operator!=(const LetterBag & other) const; // return false if the current object and other are equal.

    LetterBag makeSet();

private:
   // you fill this part in depending on how you decide to store the letters.
   int LetterCount[26] = {0}; /// a = LetterCount[0], b = LetterCount[1]
};

#endif
