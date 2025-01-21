#include <stdio.h>

int main() {
    int i, j, k, n;
    float A[20][20], c, x[20], sum = 0.0;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of augmented matrix row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // Forward Elimination
    for (j = 0; j < n; j++) {
        for (i = j + 1; i < n; i++) {
            c = A[i][j] / A[j][j];
            for (k = 0; k <= n; k++) {
                A[i][k] -= c * A[j][k];
            }
        }
    }

    // Backward Substitution
    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sum) / A[i][i];
    }

    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    return 0;
}
