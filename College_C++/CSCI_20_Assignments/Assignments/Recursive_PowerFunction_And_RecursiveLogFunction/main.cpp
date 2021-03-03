#include <iostream>
using namespace std;

double power(double base, int exponent)
{
	if (exponent != 0)								 // Base Case b^0 = 1
		return(base * power(base, exponent - 1));    // recursively call base * (base * power - 1)
	return(1);
}

int log(double base, double total, int exponent = 0)
{
	if (total == power(base, exponent))
		return(exponent);
	log(base, total, exponent + 1);
}

int main()
{               // base , power
	double pow = power(-2, 9);
	cout << pow << endl;
			// LogBase , total
	cout << log(2,1024) << endl;
}
