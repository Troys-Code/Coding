//
// friends.cpp
//
//
// Illustrate simple friend functions
//

#include <iostream>
using namespace std;

class MyInt
{
    // friendship must be granted from within the class
    // friends are standalone functions, classes or methods
    // of other classes -- NOT class members
    // so they are neither public nor private
    friend void changeMyInt( MyInt &m, int i );
    friend ostream &operator <<( ostream &out, MyInt &i );
private:
    int myint;               // data field
public:
    void setMyInt( int i );  // simple manipulator
    int  getMyInt( void );   // simple observer
};

// changeMyInt is a friend function, so it can "reach into"
// the class and modify its private data member via reference m.
void changeMyInt( MyInt &m, int i )
{
    m.myint = i;
}

// operator << is a friend output function.  It can't be a method
// since the LHS operand of an operator method must be "self" and
// LHS operand of << or >> is always the stream object.
ostream &operator <<( ostream &out, MyInt &i )
{
    return out << i.myint << flush;
}

// these are member functions, so they have access to myInt
void MyInt::setMyInt( int i )
{
    myint = i;
}
int MyInt::getMyInt( void )
{
    return myint;
}

// now some code to drive it all

int main( void )
{
    MyInt i;

    i.setMyInt( 10 );
    cout << "The value of MyInt i is " << i.getMyInt() << endl;
    changeMyInt( i, 25 );
    cout << "The value of MyInt i is " << i.getMyInt() << endl;
    i.setMyInt( 35 );
    cout << "Printing itself, MyInt i is " << i << endl;
    return 0;
}


