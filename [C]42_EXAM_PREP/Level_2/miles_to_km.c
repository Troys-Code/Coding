#include <stdio.h>

int main()
{
	int miles, yards;
	double kilometers;

	printf("\nEnter miles ");
	scanf("%d", &miles);

	printf("\nEnter yards ");
	scanf("%d", &yards);	
	
	kilometers = 1.609 * (miles + yards/1760.0);	// The division by .0 to conv to float
	printf("\n %d miles + %d yards is %lf kilometers.\n", miles, yards, kilometers);
	return 0;
}
