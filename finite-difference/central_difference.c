#include <stdio.h>
#include <math.h>




void centralDifferenceTable(double x[], double y[], int n) {
    double diff[n][n]; 

    
    for (int i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }

    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }




    
    printf("\nCentral Difference Table:\n");
    printf("======================================================\n");
    printf("|   x   |   y   | Δy1  | Δy2  | Δy3  | Δy4  | Δy5  |\n");
    printf("======================================================\n");
    for (int i = 0; i < n; i++) {
        printf("| %5.2f | %5.2f ", x[i], diff[i][0]);
        for (int j = 1; j < n - i; j++) {
            printf("| %5.2f ", diff[i][j]);
        }
        printf("\n");
    }
    printf("======================================================\n");
}



int main() {
    int n;

    
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

   
    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }
    printf("Enter the y values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

   
    centralDifferenceTable(x, y, n);

    return 0;
}
