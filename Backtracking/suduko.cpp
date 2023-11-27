#include <bits/stdc++.h>
using namespace std;

#define N 9

bool findEmptyLocation(int grid[N][N], int row, int col) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeInRow(int grid[N][N], int row, int col, int num) {
    for(int i = 0; i < N; i++) {
        if(grid[row][i] == num) {
            return false;
        }
    }
    return false;
} 

bool isSafeInColumn(int grid[N][N], int row, int col, int num) {
    for(int i = 0; i < N; i++) {
        if(grid[i][col] == num) {
            return false;
        }
    }
    return false;
} 

bool isSafeInGrid(int grid[N][N], int row, int col, int num) {
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i + rowFactor][j + colFactor] == num) {
                return false;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    if(isSafeInRow(grid, row, col, num) && isSafeInColumn(grid, row, col, num) && isSafeInGrid(grid, row, col, num)) {
        return true;
    }
    return false;
}

bool solveSuduko(int grid[N][N]) {
    int row, col;
    if(!findEmptyLocation(grid, row, col)) {
        return true;
    }

    for(int i = 1; i <= 9; i++) {
        if(isSafe(grid, row, col, i)) {
            grid[row][col] = i;
            if(solveSuduko(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    if(solveSuduko(grid)) {
        cout << "true" << endl;
        /*for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        */
    }
    else {
        cout << "false" << endl;
    }
}

