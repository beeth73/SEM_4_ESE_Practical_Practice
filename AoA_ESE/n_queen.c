#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int board[20]; // board[i] stores the column number for the queen in row i
int count = 0; // To keep track of the number of solutions

// Function to print the board configuration
void printSolution(int n) {
    int i, j;
    printf("\nSolution %d:\n", ++count);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

/* 
   The "Safe" Condition:
   A queen can be placed at (row, col) if:
   1. No queen exists in the same column: board[i] == col
   2. No queen exists on the same diagonal: abs(board[i] - col) == abs(i - row)
*/
bool isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        // Column check OR Diagonal check
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// The recursive Backtracking function
void solveNQueen(int row, int n) {
    // Base Case: If all queens are placed
    if (row > n) {
        printSolution(n);
        return;
    }

    // Try placing a queen in each column of the current 'row'
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;         // Place Queen (Place)
            solveNQueen(row + 1, n);  // Move to next row (Explore)
            // board[row] = 0;        // Implicit Backtrack (Clean up)
        }
    }
}

int main() {
    int n;

    printf("--- N-Queen Solver ---\n");
    printf("Enter the number of Queens (N): ");
    scanf("%d", &n);

    if (n <= 0 || n == 2 || n == 3) {
        printf("No solutions exist for N = %d\n", n);
    } else {
        solveNQueen(1, n);
        printf("\nTotal solutions found: %d\n", count);
    }

    return 0;
}