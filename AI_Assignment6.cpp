#include <iostream>
#include <vector>

using namespace std;

const int N = 8; // Size of the chessboard

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a queen can be placed safely at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on the left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on the left
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the 8-Queens problem
bool solveNQueens(vector<vector<int>>& board, int col) {
    // Base case: If all queens are placed, return true
    if (col >= N) {
        return true;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed at board[i][col]
        if (isSafe(board, i, col)) {
            // Place the queen
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, col + 1)) {
                return true;
            }

            // If placing the queen doesn't lead to a solution, then backtrack
            board[i][col] = 0; // Backtrack
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

int main() {
    // Initialize the 8x8 board with all zeros
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0)) {
        cout << "Solution found:" << endl;
        printBoard(board);
    } else {
        cout << "Solution does not exist." << endl;
    }

    return 0;
}