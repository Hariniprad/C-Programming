#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

char* read_str_dyn() {
    size_t size = 16;
    char *str = (char*)malloc(size);
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    size_t len = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (len >= size - 1) {
            size *= 2;
            str = (char*)realloc(str, size);
            if (str == NULL) {
                printf("Memory reallocation failed!\n");
                exit(1);
            }
        }
        str[len++] = (char)ch;
    }
    str[len] = '\0';

    return str;
}

char* read_str_fixed() {
    char *str = (char*)malloc(MAX_SIZE);
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    int ch;
    size_t len = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (len >= MAX_SIZE - 1) {
            printf("Input exceeds maximum allowed size (%d characters). Input truncated.\n", MAX_SIZE - 1);
            break;
        }
        str[len++] = (char)ch;
    }
    str[len] = '\0';

    return str;
}

int main() {
    char *IP_dyn;
    char *IP_fixed;

    printf("Enter a string with dynamic memory allocation: ");
    IP_dyn = read_str_dyn();
    printf("You entered (dynamic): %s\n", IP_dyn);

    printf("Enter a string with predefined memory size: ");
    IP_fixed = read_str_fixed();
    printf("You entered (fixed): %s\n", IP_fixed);

    free(IP_dyn);
    free(IP_fixed);

    return 0;
}
