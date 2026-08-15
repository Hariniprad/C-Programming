#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;

    // Example characters for demonstration
    char upper = 'A';
    char lower = 'a';
    char digit = '5';
    char space = ' ';
    char special = '#';

    printf("Character analysis for '%c', '%c', '%c', '%c', '%c':\n", upper, lower, digit, space, special);

    // 1. isalnum() - Check if character is alphanumeric (letter or digit)
    printf("1. isalnum('%c'): %d\n", digit, isalnum(digit));

    // 2. isalpha() - Check if character is alphabetic (letter)
    printf("2. isalpha('%c'): %d\n", upper, isalpha(upper));

    // 3. isblank() - Check if character is a blank (space or tab)
    printf("3. isblank('%c'): %d\n", space, isblank(space));

    // 4. iscntrl() - Check if character is a control character
    printf("4. iscntrl('\\n'): %d\n", iscntrl('\n'));

    // 5. isdigit() - Check if character is a digit (0-9)
    printf("5. isdigit('%c'): %d\n", digit, isdigit(digit));

    // 6. isgraph() - Check if character has a graphical representation (not space)
    printf("6. isgraph('%c'): %d\n", special, isgraph(special));

    // 7. islower() - Check if character is lowercase
    printf("7. islower('%c'): %d\n", lower, islower(lower));

    // 8. isprint() - Check if character is printable (including space)
    printf("8. isprint('%c'): %d\n", space, isprint(space));

    // 9. ispunct() - Check if character is a punctuation character
    printf("9. ispunct('%c'): %d\n", special, ispunct(special));

    // 10. isspace() - Check if character is a whitespace character (space, tab, newline, etc.)
    printf("10. isspace('\\t'): %d\n", isspace('\t'));

    // 11. isupper() - Check if character is uppercase
    printf("11. isupper('%c'): %d\n", upper, isupper(upper));

    // 12. isxdigit() - Check if character is a hexadecimal digit (0-9, a-f, A-F)
    printf("12. isxdigit('%c'): %d\n", digit, isxdigit(digit));
    printf("    isxdigit('F'): %d\n", isxdigit('F'));

    // 13. tolower() - Convert character to lowercase
    printf("13. tolower('%c'): %c\n", upper, tolower(upper));

    // 14. toupper() - Convert character to uppercase
    printf("14. toupper('%c'): %c\n", lower, toupper(lower));

    return 0;
}
