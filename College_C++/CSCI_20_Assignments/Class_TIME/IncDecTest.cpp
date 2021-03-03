//
// IncDecTest.cpp
//
// Test ++ and -- operators on a tiny integer-coordinate point class
//

#include <iostream>
using namespace std;

class Point
{
private:
	int _x, _y;
public:
    // Declare prefix and postfix increment operators
    Point& operator++();       // Prefix increment operator.
    Point operator++(int);     // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    Point& operator--();       // Prefix decrement operator.
    Point operator--(int);     // Postfix decrement operator.

    // Define default and normal constructor.
    Point() { _x = _y = 0; }
    Point( int a, int b ) { _x = a; _y = b; }

    // Define accessor functions.
    int get_x() { return _x; }
    int get_y() { return _y; }
};

// Define prefix increment operator.
Point& Point::operator++()
{
    _x++;
    _y++;
    return *this;
}

// Define postfix increment operator.
Point Point::operator++(int n)
{
    Point temp = *this;
    if( n == 0 )  // omitted argument will default to 0
    {
        ++*this;
    }
    else  // to do this, you must use the .operator++( n ) form to call
    {
        this->_x += n; // this->_x and _x are equivalent in a method
        _y += n;       // default access on an object member is on "self"
    }
    return temp;
}

// Define prefix decrement operator.
Point& Point::operator--()
{
    _x--;
    _y--;
    return *this;
}

// Define postfix decrement operator.
Point Point::operator--(int)
{
    Point temp = *this;
    --*this;
    return temp;
}

int main()
{
    Point x( 1, 1 ), y( 2, 2 ), z( 3, 3 ), t( 4, 4 );
    cout << "X is ( " << x.get_x() << ", " << x.get_y() << " )\n"
         << "Y is ( " << y.get_x() << ", " << y.get_y() << " )\n"
         << "Z is ( " << z.get_x() << ", " << z.get_y() << " )\n"
         << "T is ( " << t.get_x() << ", " << t.get_y() << " )\n" << flush;
    x = ++y;
    z = t++;
   	cout << "x = ++y; " << "z = t++;" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~\n"
         << "X is ( " << x.get_x() << ", " << x.get_y() << " )\n"
         << "Y is ( " << y.get_x() << ", " << y.get_y() << " )\n"
         << "Z is ( " << z.get_x() << ", " << z.get_y() << " )\n"
         << "T is ( " << t.get_x() << ", " << t.get_y() << " )\n" << flush;
    x.operator++(5);
    y.operator++();
	cout << "x.operator++(5); " << "y.operator++();" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~\n"
         << "X is ( " << x.get_x() << ", " << x.get_y() << " )\n" 
         << "Y is ( " << y.get_x() << ", " << y.get_y() << " )\n" << flush;
    return 0;
}

