#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long fact_for(int n) {
    unsigned long long fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }
    return fac;
}

unsigned long long fact_while(int n) {
    unsigned long long fac = 1;
    int i = 1;
    while (i <= n) {
        fac *= i;
        i++;
    }
    return fac;
}

unsigned long long fact_recursion(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact_recursion(n - 1);
}

void check_ranges() {
    printf("\nMaximum factorial value for each data type:\n");

    int i = 1;
    int fac_int = 1;
    while (1) {
        if (fac_int > INT_MAX / i) {
            break;
        }
        fac_int *= i++;
    }
    printf("int: %d! = %d\n", i - 1, fac_int);

    i = 1;
    unsigned long long fac_ll = 1;
    while (1) {
        if (fac_ll > ULLONG_MAX / i) {
            break;
        }
        fac_ll *= i++;
    }
    printf("long long int: %d! = %llu\n", i - 1, fac_ll);
}

void display_menu() {
    printf("\n--- Factorial Calculation Menu ---\n");
    printf("1. Calculate using For Loop\n");
    printf("2. Calculate using While Loop\n");
    printf("3. Calculate using Recursion\n");
    printf("4. Check Data Type Ranges\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    while (1) {
        display_menu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Enter a positive integer: ");
                scanf("%d", &n);

                if (n < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial (For Loop) of %d = %llu\n", n, fact_for(n));
                }
                break;
            }
            case 2: {
                int n;
                printf("Enter a positive integer: ");
                scanf("%d", &n);

                if (n < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial (While Loop) of %d = %llu\n", n, fact_while(n));
                }
                break;
            }
            case 3: {
                int n;
                printf("Enter a positive integer: ");
                scanf("%d", &n);

                if (n < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial (Recursion) of %d = %llu\n", n, fact_recursion(n));
                }
                break;
            }
            case 4:
                check_ranges();
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
