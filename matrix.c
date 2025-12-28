
#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2) return 1;

    if (rows > 10 || cols > 10 || rows <= 0 || cols <= 0) {
        printf("Rows and cols must be between 1 and 10.\n");
        return 1;
    }

    int matrix[10][10]; 
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) count++;
        }
    }

    int sparse[count + 1][3];
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = count;

    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;            
                sparse[k][1] = j;            
                sparse[k][2] = matrix[i][j]; 
                k++;
            }
        }
    }

    printf("\nSparse Matrix (row col value):\n");
    for (int i = 0; i <= count; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}

