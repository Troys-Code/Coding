#include <stdio.h>

void print_array(int how_many, int data[], char *str)
{
	int i;
	printf("%s", str);
	
	for( i = 0; i < how_many; i++ )
		printf( "%d\t", data[i] );
}

void merge( int a[], int b[], int c[], int how_many ) // Assumes a & b same size
{
	int i = 0;				// index of array a
	int j = 0;				// index of array b
	int k = 0;				// index of merge array c

	while( i < how_many && j < how_many )	// While still have elements
		if( a[i] < b[j] )		// if array a element smaller
			c[k++] = a[i++];	//   a[element] in merge array
		else				// else array b element smaller
			c[k++] = b[j++];	//   b[element] in merge array
						
	// Cleanup:Reach end of an array
	while( i < how_many )			// put the rest of a in sorted
		c[k++] = a[i++];
	while( j < how_many )
		c[k++] = b[j++];		// put the rest of b in sorted
}

void mergesort( int key[], int how_many)	// a power of 2 for array size
{
	int j, k;
	int w[how_many];
	
	for( k = 1; k < how_many; k *= 2)
	{
		for( j = 0; j < how_many - k; j += 2*k )
			merge( key + j, key + j+k, w + j, k );
		for( j = 0; j < how_many; j++ )
			key[j] = w[j];
	}	
}

int main()
{
	const int SIZE = 8;
	int a[SIZE] = { 101, 67, 82, 83, 88, 100, 99, 69 };
	print_array(SIZE, a, "A: grades\t");
	printf("\n\n");
	
	
	mergesort( a, SIZE );
	print_array( SIZE, a, "Sorted\t\t" );
	printf("\n\n"); 
	return 0;
}
