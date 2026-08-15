#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Creating a 2D board
void createBoard(char board[][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = '0';
        }
    }
}

// Placing mines randomly on the board
void placeMines(char board[][5], int rows, int cols, int numMines) {
    int minesPlaced = 0;
    while (minesPlaced < numMines) {
        int row = rand() % rows;
        int col = rand() % cols;
        
        // Place a mine if no mine is already placed
        if (board[row][col] != 'X') {
            board[row][col] = 'X';  // 'X' represents a mine
            minesPlaced++;
        }
    }
}

// Calculating the surrounding mine count for each cell
void calculateMineCounts(char board[][5], int rows, int cols) {
    // Directions for checking neighboring cells
    int directions[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Skip cells with mines
            if (board[i][j] == 'X') {
                continue;
            }

            // Count surrounding mines
            int mineCount = 0;
            for (int k = 0; k < 8; k++) {
                int newRow = i + directions[k][0];
                int newCol = j + directions[k][1];

                // Check if the new position is within bounds and contains a mine
                if (newRow >= 0 && newRow < rows
                    && newCol >= 0 && newCol < cols
                    && board[newRow][newCol] == 'X')
                {
                    mineCount++;
                }
            }

            // Setting cell value to the number of surrounding mines
            board[i][j] = mineCount + '0';  // Convert mine count to a character
        }
    }
}

// Displaying the board
void displayBoard(char board[][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 5;
    int cols = 5;
    int numMines = 5;

    char board[rows][cols];
        
    srand(time(NULL));  // Seed the random number generator

    createBoard(board, rows, cols);
    placeMines(board, rows, cols, numMines);
    calculateMineCounts(board, rows, cols);
    printf("Harini's Minesweeper Board:\n");
    displayBoard(board, rows, cols);

    return 0;
}
