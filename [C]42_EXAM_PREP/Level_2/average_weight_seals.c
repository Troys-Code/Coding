#include <stdio.h>
#define BUFFERSIZE 1000				// We assume 1000 entries

int main (void)
{
	int arr[BUFFERSIZE], index = 0;
	double sum = 0.0;			// Sum of all data entered
 
	// Loop through data entered until end of file
	for(double value = 0; scanf("%lf", &value) != EOF; index++)
	{
		arr[index] = value;		// Assign each index data val
		sum += arr[index];		// Accumulate sum
	}
	//printf("Number of elements = %d", index); // Tells num data elements 
	printf("Average = %lf \n",sum/index);
	return 0;
}
