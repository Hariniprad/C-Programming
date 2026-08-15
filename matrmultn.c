#include <stdio.h>
#include <stdlib.h>

void multiply_with_arrays() {
    int mat1[3][3], mat2[3][3], result[3][3];
    printf("Enter elements of first 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &mat1[i][j]);

    printf("Enter elements of second 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &mat2[i][j]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void multiply_with_pointers() {
    int mat1[3][3], mat2[3][3], result[3][3];
    printf("Enter elements of first 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", *(mat1 + i) + j);

    printf("Enter elements of second 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", *(mat2 + i) + j);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(result + i) + j) = 0;
            for (int k = 0; k < 3; k++) {
                *(*(result + i) + j) += *(*(mat1 + i) + k) * *(*(mat2 + k) + j);
            }
        }
    }

    printf("Resultant matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(*(result + i) + j));
        }
        printf("\n");
    }
}

void multiply_with_dynamic_allocation() {
    int rows = 3, cols = 3;
    int **mat1 = (int **)malloc(rows * sizeof(int *));
    int **mat2 = (int **)malloc(rows * sizeof(int *));
    int **result = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        mat1[i] = (int *)malloc(cols * sizeof(int));
        mat2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements of first 3x3 matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat1[i][j]);

    printf("Enter elements of second 3x3 matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat2[i][j]);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(result[i]);
    }

    free(mat1);
    free(mat2);
    free(result);
}

void recursive_multiplication(int mat1[3][3], int mat2[3][3], int result[3][3], int i, int j, int k) {
    if (i >= 3) return;
    if (j >= 3) {
        recursive_multiplication(mat1, mat2, result, i + 1, 0, 0);
        return;
    }
    if (k < 3) {
        result[i][j] += mat1[i][k] * mat2[k][j];
        recursive_multiplication(mat1, mat2, result, i, j, k + 1);
    } else {
        recursive_multiplication(mat1, mat2, result, i, j + 1, 0);
    }
}

void multiply_with_recursion() {
    int mat1[3][3], mat2[3][3], result[3][3] = {0};
    printf("Enter elements of first 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &mat1[i][j]);

    printf("Enter elements of second 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &mat2[i][j]);

    recursive_multiplication(mat1, mat2, result, 0, 0, 0);

    printf("Resultant matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Matrix Multiplication Menu ---\n");
        printf("1. Multiply with Arrays\n");
        printf("2. Multiply with Pointers\n");
        printf("3. Multiply with Dynamic Memory Allocation\n");
        printf("4. Multiply with Recursion\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                multiply_with_arrays();
                break;
            case 2:
                multiply_with_pointers();
                break;
            case 3:
                multiply_with_dynamic_allocation();
                break;
            case 4:
                multiply_with_recursion();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}
