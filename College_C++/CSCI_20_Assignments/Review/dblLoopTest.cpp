//
// dblLoopTest.cpp
//
// Demonstrate looping problems with floating-point numbers
//
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::flush;
using std::setw;
using std::showpoint;
using std::fixed;
using std::setprecision;
#include <cstdlib> // for system()

int main()
{
   double x = 0.0;
   for( x = 0.0; x != 1.0 && x < 2.0; x += 0.1 )
   {
      cout << showpoint << fixed << setw(8) << setprecision(6) << x << endl;
   }
   system( "pause" );
   cout << ".........|.........|.........|.........|\n";
   x = 0.0;
   while( x != 1.0 && x < 2.0 )
   {
      cout << showpoint << fixed << setw(8) << setprecision(6) << x << '\t'
           << showpoint << fixed << setw(20) << setprecision(18) << x << endl;
      x += 0.10;
   }
   return 0;
}



