#include <stdio.h>
#include <math.h> // For math functions like sin, cos, fabs
#define EPSILON 0.001




// Function to find the root
double func(double x)
{
    return x * sin(x) + cos(x);
}





// Derivative of the function
double derivFunc(double x)
{
    return x * cos(x);
}




// Newton-Raphson Method
void newtonRaphson(double x)
{
    
    while (fabs(func(x)) >= EPSILON)
    {
        if (fabs(derivFunc(x)) < EPSILON)
        {
            printf("Derivative is too small; method fails.\n");
            return;
        }

        double h = func(x) / derivFunc(x);
        x = x - h;
    }
    printf("The value of the root is : %.6lf\n", x);
}



// Driver program
int main()
{
    double x0 = 3; // Adjusted initial guess
    newtonRaphson(x0);
    return 0;
}
