#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char str[500];
    char *words[50];
    int count = 0;          

    printf("Enter a sentence:\n");
    fgets(str, 500, stdin);
    str[strcspn(str, "\n")] = 0;

    char *delim = " ,.;:!?\"'()";
    char *tok = strtok(str, delim);

    while (tok != NULL) {
        to_lower(tok);         
        int unique = 1;

        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], tok) == 0) {
                unique = 0;
                break;
            }
        }

        // Add to array if unique
        if (unique == 1) {
            words[count++] = tok;
        }

        tok = strtok(NULL, delim);
    }

    // Print unique words
    printf("Unique words:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
