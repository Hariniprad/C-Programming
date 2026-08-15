#include <stdio.h>
#include <stdlib.h>  // For stdlib functions

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);  // Used in qsort
}

int main() {
    // 1. malloc(), calloc(), realloc(), and free() - Dynamic memory allocation
    int *arr;
    arr = (int*) malloc(5 * sizeof(int));  // Allocating memory for 5 integers using malloc
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Filling the array
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }

    printf("\n");

    arr = (int*) realloc(arr, 10 * sizeof(int));  // Reallocating to a larger array
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Filling the new memory space
    for (int i = 5; i < 10; i++) {
        arr[i] = i * 10;
    }

    printf("Array after reallocating: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Free the allocated memory
    free(arr);

    // 2. abs() - Find absolute value
    int num = -15;
    printf("Absolute value of %d is %d\n", num, abs(num));

    // 3. atof(), atoi(), atol() - String to number conversion
    char str1[] = "3.14159";
    char str2[] = "123";
    char str3[] = "9876543210";

    double d = atof(str1);
    int i = atoi(str2);
    long l = atol(str3);

    printf("Converted string to double: %f\n", d);
    printf("Converted string to int: %d\n", i);
    printf("Converted string to long: %ld\n", l);

    // 4. rand(), srand() - Generate random numbers
    srand(42);  // Seed for reproducibility
    printf("Random numbers: %d, %d, %d\n", rand(), rand(), rand());

    // 5. exit() - Terminate program
    // Uncomment below line to terminate program early
    // exit(0);

    // 6. system() - Execute system command
    // system("ls");  // Executes 'ls' command on UNIX or 'dir' on Windows

    // 7. qsort() - Sort an array
    int arr2[] = {43, 21, 65, 87, 32, 89, 10};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    qsort(arr2, n, sizeof(int), compare);  // Sort array in ascending order

    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    printf("\n");

    // 8. bsearch() - Binary search in a sorted array
    int key = 65;
    int *item = (int*) bsearch(&key, arr2, n, sizeof(int), compare);

    if (item != NULL) {
        printf("Found %d in array.\n", *item);
    } else {
        printf("%d not found in array.\n", key);
    }

    // 9. div() - Integer division and remainder
    div_t result = div(10, 3);
    printf("Quotient: %d, Remainder: %d\n", result.quot, result.rem);

    return 0;
}
