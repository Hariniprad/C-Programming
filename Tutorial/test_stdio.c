#include <stdio.h>

int main() {
    char ch;
    char str[100];
    int i;
    float f;
    FILE *file;

    // 1. printf() - Print formatted output to console
    printf("1. This is an example of printf().\n");

    // 2. scanf() - Read formatted input from the console
    printf("2. Enter an integer and a float: ");
    scanf("%d %f", &i, &f);
    printf("You entered integer: %d and float: %.2f\n", i, f);

    // 3. putchar() - Write a character to the console
    printf("3. Using putchar() to print a character: ");
    putchar('A');
    putchar('\n');

    // 4. getchar() - Read a character from the console
    printf("4. Press any key: ");
    ch = getchar();  // Reading a single character
    printf("You pressed: ");
    putchar(ch);     // Printing the character using putchar()
    putchar('\n');

    // 5. puts() - Write a string to the console
    printf("5. Using puts() to print a string:\n");
    puts("Hello, World!");

    // 6. gets() - Read a string from the console (Deprecated, use fgets() instead)
    printf("6. Enter a string (using fgets()): ");
    fgets(str, sizeof(str), stdin);  // Safely reads a string with fgets()
    printf("You entered: ");
    puts(str);

    // 7. sprintf() - Write formatted data to a string
    char buffer[50];
    sprintf(buffer, "Integer: %d, Float: %.2f", i, f);
    printf("7. Using sprintf() to write to buffer: %s\n", buffer);

    // 8. sscanf() - Read formatted data from a string
    char input[] = "123 45.67";
    sscanf(input, "%d %f", &i, &f);
    printf("8. Using sscanf() to read from a string: Integer: %d, Float: %.2f\n", i, f);

    // 9. fopen() - Open a file for reading or writing
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("9. File 'example.txt' opened successfully.\n");

    // 10. fprintf() - Write formatted output to a file
    fprintf(file, "Writing to file using fprintf().\n");

    // 11. fputs() - Write a string to a file
    fputs("Writing a string using fputs().\n", file);

    // 12. fclose() - Close a file
    fclose(file);
    printf("12. File closed successfully.\n");

    // 13. fopen() again to read the file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    // 14. fgets() - Read a string from a file
    printf("13. Contents of 'example.txt':\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // 15. fread() and fwrite() - Read and write binary data
    int numbers[5] = {1, 2, 3, 4, 5};
    file = fopen("binary.dat", "wb");
    fwrite(numbers, sizeof(int), 5, file);  // Writing binary data
    fclose(file);

    int read_numbers[5];
    file = fopen("binary.dat", "rb");
    fread(read_numbers, sizeof(int), 5, file);  // Reading binary data
    fclose(file);
    printf("14. Using fread() and fwrite() for binary data:\n");
    for (int j = 0; j < 5; j++) {
        printf("%d ", read_numbers[j]);
    }
    printf("\n");

    // 16. remove() - Delete a file
    if (remove("example.txt") == 0) {
        printf("15. File 'example.txt' deleted successfully.\n");
    } else {
        printf("Error deleting the file!\n");
    }

    // 17. rename() - Rename a file
    if (rename("binary.dat", "renamed.dat") == 0) {
        printf("16. File renamed to 'renamed.dat'.\n");
    } else {
        printf("Error renaming the file!\n");
    }

    // 18. rewind() - Reset file pointer to the beginning of the file
    file = fopen("renamed.dat", "rb");
    fread(read_numbers, sizeof(int), 5, file);  // Reading binary data
    rewind(file);  // Reset file pointer
    fread(read_numbers, sizeof(int), 5, file);  // Reading again after rewind
    printf("17. Using rewind() to read the binary file again.\n");
    fclose(file);

    // 19. ftell() - Get the current position of the file pointer
    file = fopen("renamed.dat", "rb");
    fseek(file, 0, SEEK_END);  // Move pointer to the end of the file
    long pos = ftell(file);    // Get current position
    printf("18. Using ftell(): The size of 'renamed.dat' is %ld bytes.\n", pos);
    fclose(file);

    return 0;
}
