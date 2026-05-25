#include <stdio.h>
#include <stdlib.h>

// Checks if it's safe to place a queen at board[row] = col
int isSafe(int *board, int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check column conflict OR diagonal conflicts
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

// Backtracking function
void solve(int row, int n, int *board) {
    if (row == n) { // Base case: Solution found, print it
        for (int i = 0; i < n; i++, printf("\n"))
            for (int j = 0; j < n; j++) printf(board[i] == j ? " Q " : " . ");
        printf("-----------------\n");
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // Place queen
            solve(row + 1, n, board); // Recur
        }
    }
}

int main() {
    int n;
    printf("Enter N: ");
    if (scanf("%d", &n) == 1 && n > 0) {
        int *board = calloc(n, sizeof(int));
        solve(0, n, board);
        free(board);
    }
    return 0;
}
