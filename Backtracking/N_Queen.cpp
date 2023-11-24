#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int col) {
    // Same column
    for(int i = row - 1; i >= 0; i--) {
        if(board[i][col] == 1) {
            return false;
        }
    }

    // Upper left diagonal
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    
    // Upper right diagonal
    for(int i = row - 1, j = col + 1; i >= 0 && j <= n; i--, j++) {
        if(board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void NqueenHelper(int n, int row) {
    if(row == n) {
        // We have reached some solution.
        // Print the solution
        //return
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Place at all possible positions & move to smaller problem
    for(int j = 0; j < n; j++) {
        if(isPossible(n, row, j)) {
            board[row][j]= 1;
            NqueenHelper(n, row + 1);
            board[row][j] = 0;
        }
    }
    return;
}

void placeQueens(int n) {
    memset(board, 0, 11*11*sizeof(int));
    NqueenHelper(n, 0);
}

int main() {
    placeQueens(4);
    return 0;
}