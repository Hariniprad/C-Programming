#include <stdio.h>
#include <unistd.h>
 
// Define the maze as a 2D character array
char maze[5][7] = {
	{'S', '0', '0', '1', '0', '1', '0'},
	{'0', '0', '0', '1', '0', '1', '0'},
	{'1', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '0', '0', '1', '0'},
	{'0', '0', '0', '0', '0', '0', 'E'}
};
 
// Function to recursively solve the maze
int solveMaze(int x, int y) {
	// Check if we have reached the exit
	if (maze[x][y] == 'E') {
    	return 1; // Maze is solved
	}
 
	// Check if the current cell is a valid path
	if (maze[x][y] == '0' || maze[x][y] == 'S') {
    	// Mark the current cell as part of the path
    	maze[x][y] = '*';
 
    	// Try moving in all four directions (up, down, left, right)
    	if (solveMaze(x + 1, y) || solveMaze(x - 1, y) || solveMaze(x, y + 1) || solveMaze(x, y - 1)) {
        	return 1; // Maze is solved
    	}
 
    	// If none of the directions lead to a solution, backtrack
    	maze[x][y] = '.';
	}
 
	return 0; // No solution found
}
 
int main() {
	printf("Maze Solver Example:\n\n");
 
	// Print the initial maze
    printf("Initial Maze:\n");
	for (int i = 0; i < 5; i++) {
    	for (int j = 0; j < 7; j++) {
            printf("%c", maze[i][j]);
    	}
        printf("\n");
	}
 
	// Solve the maze starting from the 'S' position
	if (solveMaze(0, 0)) {
    	printf("\nSolved Maze:\n");
    	for (int i = 0; i < 5; i++) {
        	for (int j = 0; j < 7; j++) {
                printf("%c", maze[i][j]);                
        	}
            printf("\n");
    	}
	} else {
        printf("\nNo solution found.\n");
	}
 
	return 0;
}

