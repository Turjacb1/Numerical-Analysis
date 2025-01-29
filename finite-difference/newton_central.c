#include <stdio.h>
#include <math.h>

#define MAX 10 


int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}


void centralDifferenceTable(double x[], double y[][MAX], int n) {
    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    
    printf("\nCentral Difference Table:\n");
    printf("======================================================\n");
    printf("|   x   |   y   | Δy1  | Δy2  | Δy3  | Δy4  | Δy5  |\n");
    printf("======================================================\n");
    for (int i = 0; i < n; i++) {
        printf("| %5.2lf | %5.2lf ", x[i], y[i][0]);
        for (int j = 1; j < n - i; j++) {
            printf("| %5.2lf ", y[i][j]);
        }
        printf("\n");
    }
    printf("======================================================\n");
}


double centralDifferenceInterpolation(double x[], double y[][MAX], int n, double x_value) {
    int mid = n / 2; 
    double h = x[1] - x[0]; 
    double u = (x_value - x[mid]) / h; 
    double result = y[mid][0]; 

    
    double term = 1;
    int sign = 1;
    for (int i = 1; i < n; i++) {
        term *= (u - sign * (i / 2.0)) / i; 
        result += term * y[mid - i / 2][i];
        sign = -sign;
    }

    return result;
}


int main() {
    int n;
    double x[MAX], y[MAX][MAX], x_value;

    
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    
    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }
    printf("Enter the y values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i][0]); 
    }

    
    centralDifferenceTable(x, y, n);

   
    printf("\nEnter the value of x for interpolation: ");
    scanf("%lf", &x_value);

    
    double interpolated_value = centralDifferenceInterpolation(x, y, n, x_value);

    
    printf("\nInterpolated value at x = %.2lf is %.6lf\n", x_value, interpolated_value);

    return 0;
}
