// by nethra
#include <stdio.h>
#include <stdlib.h>

#define OPEN 0
#define OBSTACLE -1
#define PATH 2

// Directions for row movement (down, right, up, left)
int row_dir[] = {0, 1, 0, -1}; 
int col_dir[] = {1, 0, -1, 0};

typedef struct {
    int x, y;
} point;

// Perform DFS
int DFS(int **grid, int rows, int columns, point current, point end) {
    // Base case: if current point is out of bounds or an obstacle
    if (current.x < 0 || current.x >= rows || current.y < 0 || current.y >= columns ||
        grid[current.x][current.y] != OPEN) {
        return 0; // Invalid move
    }

    // Mark the current cell as part of the path
    grid[current.x][current.y] = PATH;

    // If we have reached the end point
    if (current.x == end.x && current.y == end.y) {
        return 1; // Path found
    }

    // Explore all four possible directions
    for (int i = 0; i < 4; i++) {
        point next = {current.x + row_dir[i], current.y + col_dir[i]};
        if (DFS(grid, rows, columns, next, end)) {
            return 1; // If path found in any direction
        }
    }

    // Backtrack
    grid[current.x][current.y] = OPEN;
    return 0; // No path found
}

// Print the grid
void printGrid(int **grid, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j] == OPEN)
                printf(". ");
            else if (grid[i][j] == OBSTACLE)
                printf("# ");
            else if (grid[i][j] == PATH)
                printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int rows, columns;

    // Get number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Dynamically allocate memory for the grid
    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(columns * sizeof(int));
    }

    // Get grid values from the user
    printf("Enter the grid values (0 for OPEN, -1 for OBSTACLE):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter value for grid[%d][%d]: ", i, j);
            scanf("%d", &grid[i][j]);
        }
    }

    point start, end;

    // Get the start and end points from the user
    printf("Enter the start point (x y): ");
    scanf("%d %d", &start.x, &start.y);

    printf("Enter the end point (x y): ");
    scanf("%d %d", &end.x, &end.y);

    // Validate start and end points
    if (start.x < 0 || start.x >= rows || start.y < 0 || start.y >= columns || grid[start.x][start.y] == OBSTACLE) {
        printf("Invalid start point.\n");
        return 1;
    }
    if (end.x < 0 || end.x >= rows || end.y < 0 || end.y >= columns || grid[end.x][end.y] == OBSTACLE) {
        printf("Invalid end point.\n");
        return 1;
    }

    printf("\nOriginal Grid:\n");
    printGrid(grid, rows, columns);

    // Perform DFS to find the path
    if (DFS(grid, rows, columns, start, end)) {
        printf("\nPath Found:\n");
        printGrid(grid, rows, columns);
    } else {
        printf("\nNo path found.\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
