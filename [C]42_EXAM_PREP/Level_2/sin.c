#include <stdio.h> // Imported for scanf() and printf()
#include <math.h> // Imported for M_PI value of PI and sin() function

int main(void)
{
    double radians;
    printf("\nPlease Enter an Angle in Radians between (0 - 1) :  ");
    scanf("%lf", &radians);
    
    if( radians > 0 && radians < 1) // Assuming non inclusive 0-1 is not including 0 or 1, otherwise >= and <=
        printf("\nThe Sine of %f = %f \n", radians, sin(radians));
        
  return 0;
}
