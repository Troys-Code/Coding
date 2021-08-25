#include <stdio.h>

int main()
{
	int degree, celsius;

	printf("\nEnter a degree in F: ");
	scanf("%d", &degree);
	celsius = (degree-32)/1.8;		// Conversion C=(F-32)/1.8
	printf("\n %d degrees Fahrenheit is %d degrees celsius.\n", degree, celsius);
	return 0;
}
