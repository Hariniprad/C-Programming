#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char str[1000];
    char *uniWords[100];
    int f[100] = {0};
    int count = 0;

    printf("Enter a string:\n");
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = 0;

    char *delim = " ";
    char *tok = strtok(str, delim);

    while (tok != NULL) {
        to_lowercase(tok);
        int word = -1;

        for (int i = 0; i < count; i++) {
            if (strcmp(uniWords[i], tok) == 0) {
                word = i;
                break;
            }
        }

        if (word != -1) {
            f[word]++;
        } else {
            uniWords[count] = tok;
            f[count] = 1;
            count++;
        }

        tok = strtok(NULL, delim);
    }

    printf("\nFrequencies Of Words In The String Entered:\n");
    for (int i = 0; i < count; i++) {
        printf("%s = %d\n", uniWords[i], f[i]);
    }

    return 0;
}
