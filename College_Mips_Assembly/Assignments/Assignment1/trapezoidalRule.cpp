// C++ program to implement Trapezoidal rule
#include <iostream>

// A sample function whose definite integral's
// approximate value is computed using Trapezoidal rule
float f(float x)
{
    // Declaring the function f(x) = 1/(x)
    return 1 / (x);
}

// Function to evalute the value of integral
float trapezoidal(float a, float b, float n)
{
    // Grid spacing
    float deltaX = (b - a) / n;

    // Computing sum of first and last terms in above formula
    float sum = f(a) + f(b);

    // Adds middle terms in above formula excluding the first and last term
    for (int i = 1; i < n; i++)
        sum += 2 * f(a + i * deltaX);

    // deltaX / 2 indicates (b-a)/2n. Multiplying deltaX / 2 with sum.
    return (deltaX / 2) * sum;
}

int main()
{
    // Range of definite integral from A to B
    float xA = 1;
    float xB = 2;

    // Number of grids. Higher value means more accuracy
    int n = 10;

    std::cout << "Value of integral is " << trapezoidal(xA, xB, n) << std::endl;
    return 0;
}
