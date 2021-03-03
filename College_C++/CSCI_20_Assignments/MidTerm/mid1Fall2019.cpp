//
// mid1Fall2019.cpp
//
// CSCI-15 midterm #1
// You must run this with command line arguments
//

#include <iostream>
#include <fstream>
#include <ctime>     // for time()
#include <cstdlib>   // for NULL, rand(), srand()
using namespace std;

// Question #1
// all MoveHare() needs to do is move the hare, i.e., adjust its index
// you could have named constants for the limits
// this function's code could just be embedded in MoveHare() for the exam
void CheckLimits( int &p )
{
    if( p < 1 )
    {
        p = 1;
    }
    else if( p > 70 )
    {
        p = 70;
    }
    return;
}
void MoveHare( int &h )
{
    // this is static for efficiency
    static int offsets[10] = { 0, 0, 9, 9, -12, 1, 1, 1, -2, -2 };
    int i = rand() % 10;
    h += offsets[i];
    CheckLimits( h );
    return;
}

// Question #2
// version 1
int StrComp1( char s[], char t[] )
{
    int i = 0;
    while( s[i] && s[i] == t[i] )
    {
        i++;
    }
    return s[i] - t[i];
}
// version 2
int StrComp2( char *s, char *t )
{
    int i = 0;
    while( *(s+i) && *(s+i) == *(t+i) )
    {
        i++;
    }
    return *(s+i) - *(t+i);
}

// version 3
int StrComp3( char *s, char *t )
{
    while( *s && *s == *t)
    {
        s++;
        t++;
    }
    return *s - *t;
}

// Question #3
int main3( int argc, char *argv[] )
{
    long rule;
    ifstream fin;
    ofstream fout;
    if( argc < 4 )
    {
        cout << "Usage: progname input output seed" << endl;
        exit( -1 );
    }
    fin.open( argv[1] );
    fout.open( argv[2] );
    if( !fin || !fout )
    {
        cout << "Error opening files" << endl;
        exit( -2 );
    }
    rule = atol( argv[3] );
    if( rule > 0 )
    {
        srand( rule );
    }
    else if( rule == 0 )
    {
        srand( time( NULL ) );
    }
    return 0;
}

// Question 4 code
int test( int a, int &b )
{
    int c = a + b - 2;
    a = b + c;
    b = a + c;
    cout << a << ' ' << b << ' ' << c << '\n';
    return a + b + c;
}
int main4( void )
{
    int a = 1, b = 2, c;
    c = test( a, b );
    cout << "a = " << a << " b = " << b
         << " c = " << c << '\n';
    b = test( c, a );
    cout << "a = " << a << " b = " << b
         << " c = " << c << '\n';
    return 0;
}

#if 0
// Question 4 output
3 4 1
a = 1 b = 4 c = 8
8 15 7
a = 15 b = 30 c = 8
#endif // 0

#if 0
// Question #5
given the declarations
    int a[10];
    int i;
Why are a[i] and i[a] equivalent?

a is of type const int * (pointer to the base of array a)
a[i] is compiled to *(a+i)
i[a] is compiled to *(i+a)
addition is commutative
i is coerced for addition to a by multiplying it by the size of an int
so (a+i) and (i+a) evaluate to the same address
#endif // 0

int main( int argc, char **argv )
{
    main3( argc, argv );
    cout << "------------------------------------" << endl;
    main4();
    // END OF Question #4 -- call MoveHare() to check it...
    int h = rand() % 45 + 7;  // random starting position 7...53
    cout << "Position of hare : " << h << endl;
    MoveHare( h );
    cout << "New position of hare : " << h << endl;
    MoveHare( h );
    cout << "New position of hare : " << h << endl;
// Now call StrCompX() to check them
    char str1[100] = "The quick brown fox", str2[100] = "The big brown bear";
    cout << "StrComp1(1,2) returns : " << StrComp1( str1, str2 ) << endl;
    cout << "StrComp2(2,1) returns : " << StrComp2( str2, str1 ) << endl;
    cout << "StrComp3(1,1) returns : " << StrComp3( str1, str1 ) << endl;
    return 0;
}
