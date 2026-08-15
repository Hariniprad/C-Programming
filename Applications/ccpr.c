#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LEN 10000
#define CLIPBOARD_SIZE 1000

char text[MAX_TEXT_LEN];
char clipboard[CLIPBOARD_SIZE];
char undo_stack[MAX_TEXT_LEN];
char redo_stack[MAX_TEXT_LEN];
int undo_available = 0, redo_available = 0;

void save_undo() {
    strcpy(undo_stack, text);
    undo_available = 1;
}

void save_redo() {
    strcpy(redo_stack, text);
    redo_available = 1;
}

void undo() {
    if (undo_available) {
        save_redo();
        strcpy(text, undo_stack);
        undo_available = 0;
        printf("Undo successful!\n");
    } else {
        printf("No actions to undo.\n");
    }
}

void redo() {
    if (redo_available) {
        save_undo();
        strcpy(text, redo_stack);
        redo_available = 0;
        printf("Redo successful!\n");
    } else {
        printf("No actions to redo.\n");
    }
}

void load_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    fread(text, sizeof(char), MAX_TEXT_LEN, file);
    fclose(file);
    printf("File loaded successfully!\n");
}

void save_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error saving file");
        exit(1);
    }
    fwrite(text, sizeof(char), strlen(text), file);
    fclose(file);
    printf("File saved to %s successfully!\n", filename);
}

void cut_text(int start, int end) {
    save_undo();
    strncpy(clipboard, text + start, end - start);
    clipboard[end - start] = '\0';
    memmove(text + start, text + end, strlen(text + end) + 1);
    printf("Text cut and saved to clipboard.\n");
}

void copy_text(int start, int end) {
    strncpy(clipboard, text + start, end - start);
    clipboard[end - start] = '\0';
    printf("Text copied to clipboard.\n");
}

void paste_text(int position) {
    save_undo();
    char temp[MAX_TEXT_LEN];
    strcpy(temp, text + position);
    strcpy(text + position, clipboard);
    strcat(text, temp);
    printf("Text pasted from clipboard.\n");
}

void duplicate_text(int start, int end) {
    save_undo();
    char temp[MAX_TEXT_LEN];
    strncpy(temp, text + start, end - start);
    temp[end - start] = '\0';
    strcat(text, temp);
    printf("Selected text duplicated.\n");
}

void find_text(const char *word) {
    int occurrences = 0;
    char *pos = text;
    while ((pos = strstr(pos, word)) != NULL) {
        printf("Found at position: %ld\n", pos - text);
        pos += strlen(word);
        occurrences++;
    }
    if (occurrences == 0) {
        printf("No occurrences found.\n");
    }
}

void replace_text(const char *old_word, const char *new_word) {
    save_undo();
    char temp[MAX_TEXT_LEN] = {0};
    char *pos = text, *last_pos = text;
    while ((pos = strstr(last_pos, old_word)) != NULL) {
        strncat(temp, last_pos, pos - last_pos);
        strcat(temp, new_word);
        last_pos = pos + strlen(old_word);
    }
    strcat(temp, last_pos);
    strcpy(text, temp);
    printf("All occurrences replaced.\n");
}

void convert_case(int to_upper) {
    save_undo();
    for (int i = 0; text[i]; i++) {
        text[i] = to_upper ? toupper(text[i]) : tolower(text[i]);
    }
    printf("Case conversion completed.\n");
}

void display_menu() {
    printf("\n--- String Manipulation Menu ---\n");
    printf("1. Cut\n2. Copy\n3. Paste\n4. Duplicate\n");
    printf("5. Find\n6. Replace\n7. Case Conversion\n");
    printf("8. Undo\n9. Redo\n10. Save to File\n11. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char filename[100];
    printf("Enter the filename to load: ");
    scanf("%s", filename);
    load_file(filename);

    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int start, end;
                printf("Enter start and end positions to cut: ");
                scanf("%d %d", &start, &end);
                cut_text(start, end);
                break;
            }
            case 2: {
                int start, end;
                printf("Enter start and end positions to copy: ");
                scanf("%d %d", &start, &end);
                copy_text(start, end);
                break;
            }
            case 3: {
                int pos;
                printf("Enter the position to paste: ");
                scanf("%d", &pos);
                paste_text(pos);
                break;
            }
            case 4: {
                int start, end;
                printf("Enter start and end positions to duplicate: ");
                scanf("%d %d", &start, &end);
                duplicate_text(start, end);
                break;
            }
            case 5: {
                char word[100];
                printf("Enter the word to find: ");
                scanf("%s", word);
                find_text(word);
                break;
            }
            case 6: {
                char old_word[100], new_word[100];
                printf("Enter the word to replace: ");
                scanf("%s", old_word);
                printf("Enter the new word: ");
                scanf("%s", new_word);
                replace_text(old_word, new_word);
                break;
            }
            case 7: {
                int to_upper;
                printf("Enter 1 for UPPERCASE or 0 for lowercase: ");
                scanf("%d", &to_upper);
                convert_case(to_upper);
                break;
            }
            case 8:
                undo();
                break;
            case 9:
                redo();
                break;
            case 10: {
                char save_filename[100];
                printf("Enter filename to save: ");
                scanf("%s", save_filename);
                save_file(save_filename);
                break;
            }
            case 11:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\nCurrent Text:\n%s\n", text);
    }
    return 0;
}
