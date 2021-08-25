#include <stdio.h>  // For printf()
#include <math.h>   // For sin() , cos()

// Prints table of values for sine and cosine, its result is between (0, 1)
void print_sin_cos()
{
	// sine and cosine only positive from 0 - 1.5 rad or pi/2 or 90 degrees
	for (double x = 0.0; x <= 1.6; x += 0.1)
		printf("sin(%f)=%f \t cos(%f)=%f\n", x, sin(x), x, cos(x));
}

int main(void)
{
	printf("\tA table of values for sine and cosine between (0, 1)\n");
	print_sin_cos();
	return 0;
}
