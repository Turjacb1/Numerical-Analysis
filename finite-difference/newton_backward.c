#include <stdio.h>

double factorial(int n);



void backward(double x[], double y[], int n, double x_val) {
    double dif[n][n];

 
    for (int i = 0; i < n; i++) {
        dif[i][0] = y[i];
    }



    
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            dif[i][j] = dif[i][j - 1] - dif[i - 1][j - 1];
        }
    }


    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("dif[%d][%d] = %lf\n", i, j, dif[i][j]);
        }
    }



    double u = (x_val - x[n - 1]) / (x[1] - x[0]);  
    double y_val = y[n - 1];  

    
    for (int i = 1; i < n; i++) {
        double uterm = 1;
        for (int j = 0; j < i; j++) {
            uterm *= (u + j);
        }
        y_val += (uterm * dif[n - 1][i]) / factorial(i);
    }

    printf("Interpolated value of sin(%.2lf) is: %lf\n", x_val, y_val);
}



double factorial(int n) {
    double fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}



int main() {
    int n = 6;
    double x[] = {15, 20, 25, 30, 35, 40};
    double y[] = {0.2588190, 0.3420201, 0.4226183, 0.5, 0.5735764, 0.6427876};
    double x_val = 38;  

    backward(x, y, n, x_val);
    return 0;
}
