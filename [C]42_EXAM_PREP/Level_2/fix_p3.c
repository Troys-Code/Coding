#include<stdio.h>
#include<math.h> // has  sin(), abs(), and fabs()

int main(void)
{ 
	double interval;
	int i;
	for(i = 0; i < 30; i++)
	{
    		interval = i/10.0;
    		printf("sin(%lf) = %lf \t", interval, fabs(sin(interval)));
	}

	printf("\n+++++++\n");
	return 0;
}

// Given the interval of interest we will only have positive resultants, therefore the code was correct from the start
// However I used fabs() because its intended to be used for floating point values
