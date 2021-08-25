#include<stdio.h>
#define PI 3.14159

int main(void)
{
	double radius;
	printf("Enter radius:");
	scanf("%lf", &radius);
	printf( "volume is : %f \n\n", (4/3.0) * PI * (radius*radius*radius) );	// V= (4/3) * (PI) * (r^3)
	return 0;
}
