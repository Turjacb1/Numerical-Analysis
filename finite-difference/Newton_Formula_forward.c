




#include <stdio.h>

double factorial(int n);  

void forward(double x[], double y[], int n) {
    double dif[n][n];

    
    for (int i = 0; i < n; i++) {
        dif[i][0] = y[i];
    }

    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dif[i][j] = dif[i + 1][j - 1] - dif[i][j - 1];
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("dif[%d][%d] = %lf\n", i, j, dif[i][j]);
        }
    }

    double u = (8 - x[0]) / (x[1] - x[0]);  
    double y8 = y[0];

    
    for (int i = 1; i < n; i++) {
        double uterm = 1;
        for (int j = 0; j < i; j++) {
            uterm *= (u - j);
        }
        y8 += (uterm * dif[0][i]) / factorial(i);
    }

    printf("Interpolated value at x = 8 is: %lf\n", y8);
}

double factorial(int n) {
    double fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n = 4;
    double x[4], y[4];

    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter the values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    forward(x, y, n);
    return 0;
}
