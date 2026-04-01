#include <stdio.h>

void displayMatrix(int matrix[4][4], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[4][4], alt[4][4] = {0};
    int countZero = 0, n = 4;

    printf("Enter elements of 4x4 matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0) countZero++;
        }
    }

    printf("\nOriginal matrix:\n");
    displayMatrix(matrix, n);

    if (countZero > (n * n) / 2) {
        int r = 0, c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    alt[r][c] = matrix[i][j];
                    c++;
                    if (c == n) {
                        c = 0;
                        r++;
                    }
                }
            }
        }
        printf("\nMatrix is sparse.\nNon-zero elements stored in alternate matrix:\n");
        displayMatrix(alt, n);
    } else {
        printf("\nMatrix is not sparse.\n");
    }

    return 0;
}