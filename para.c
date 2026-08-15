#include <stdio.h>
#include <string.h>

// MAX_LINES = n
// MAX_LENGTH = l

#define n 100
#define l 200

// Function to count leading tabs
int count_tabs(const char *line) {
    int count = 0;
    while (line[count] == '\t') {
        count++;
    }
    return count;
}

// Function to sort and group lines based on indentation (tabs)
void sort_and_group_lines_by_indentation(char lines[n][l], int num_lines) {
    // Group lines by indentation level
    char grouped_lines[n][l];
    int indent_levels[n];
    int group_counts[n] = {0};

    // Store the lines with their respective indentation levels
    for (int i = 0; i < num_lines; i++) {
        int indent_level = count_tabs(lines[i]);
        indent_levels[i] = indent_level;
        strcpy(grouped_lines[indent_level * n + group_counts[indent_level]], lines[i]);
        group_counts[indent_level]++;
    }

    // Print grouped lines by indent level
    for (int level = 0; level < n; level++) {
        if (group_counts[level] > 0) {
            printf("Group %d indentations:\n", level);
            for (int i = 0; i < group_counts[level]; i++) {
                printf("- %s\n", grouped_lines[level * n + i]);
            }
            printf("\n");
        }
    }
}

int main() {
    char lines[n][l];
    int num_lines = 0;

    // Reading the lines from standard input
    printf("Enter lines of text (Ctrl+D to end input):\n");
    while (fgets(lines[num_lines], l, stdin)) {
        // Remove newline character from the end of each line
        lines[num_lines][strcspn(lines[num_lines], "\n")] = '\0';
        num_lines++;
    }

    // Sort and group the lines by indentation
    sort_and_group_lines_by_indentation(lines, num_lines);

    return 0;
}
