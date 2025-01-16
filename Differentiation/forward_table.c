#include <stdio.h>
#include <math.h>


void forward(double x[], double y[], int n);


int main()
{
    int n;
    printf("value of n = ");
    scanf("%d", &n);
    double x[n], y[n];

    printf("value of x = ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %lf", &x[i]);
    }

    printf("value of y = ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &y[i]);
    }

    forward(x, y, n);
    return 0;
}







void forward(double x[], double y[], int n)
{
    double diff[n][n];

    
    for (int i = 0; i < n; i++)
    {
        diff[i][0] = y[i];
    }



    
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }






    
    printf("Forward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("  diff[%d][%d] = %lf\n", i, j, diff[i][j]);
        }
    }







 
    double h = x[1] - x[0]; 
    double sum = 0.0;
    int sign = 1;

    for (int i = 1; i < n; i++)
    {
        double term = diff[1][i] / i;
        sum += sign * term;
        sign = -sign;
    }



    double first_derivative = sum / h;

    
    printf("\nFirst derivative at x = %0.2f is approximately %0.2f\n", x[1], first_derivative);
}
