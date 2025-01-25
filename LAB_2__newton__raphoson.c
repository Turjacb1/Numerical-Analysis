#include <stdio.h>
#include <math.h> 
#define EPSILON 0.001





double func(double x)
{
    return x * sin(x) + cos(x);
}





double derivFunc(double x)
{
    return x * cos(x);
}




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





int main()
{
    double x0 = 3; 
    newtonRaphson(x0);
    return 0;
}


