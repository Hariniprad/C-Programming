#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000
#define MAX_WORDS 100

void to_lowercase(const char *src, char *dest) {
    while (*src) {
        *dest++ = tolower(*src++);
    }
    *dest = '\0';
}

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char str[MAX_LEN];
    char *words[MAX_WORDS];
    char l_w[MAX_WORDS][MAX_LEN];
    int count = 0;

    printf("Enter a sentence: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';

    char *delim = " ";
    char *tok = strtok(str, delim);

    while (tok != NULL) {
        words[count] = tok;
        to_lowercase(tok, l_w[count]);
        count++;
        tok = strtok(NULL, delim);
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(l_w[i], l_w[j]) > 0) {
                swap(&words[i], &words[j]);

                char temp[MAX_LEN];
                strcpy(temp, l_w[i]);
                strcpy(l_w[i], l_w[j]);
                strcpy(l_w[j], temp);
            }
        }
    }

    printf("\nWords in Alphabetical Order:\n");
    for (int i = 0; i < count; i++) {
        if (i > 0) printf(" ");
        printf("%s", words[i]);
    }
    printf("\n");

    return 0;
}
