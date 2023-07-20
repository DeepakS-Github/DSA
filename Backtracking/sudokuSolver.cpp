#include <iostream>
using namespace std;


bool check(int board[9][9], int row, int col) {
    int arr[10] = {0};

    // Check row
    for (int i = 0; i < 9; i++) {
        arr[board[row][i]]++;
    }

    for (int i = 1; i < 10; i++) {
        if (arr[i] > 1) {
            return false;
        }
        arr[i] = 0;
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        arr[board[i][col]]++;
    }

    for (int i = 1; i < 10; i++) {
        if (arr[i] > 1) {
            return false;
        }
        arr[i] = 0;
    }

    // Check subgrid
    int subgridRow = (row / 3) * 3;
    int subgridCol = (col / 3) * 3;

    for (int i = subgridRow; i < subgridRow + 3; i++) {
        for (int j = subgridCol; j < subgridCol + 3; j++) {
            arr[board[i][j]]++;
        }
    }

    for (int i = 1; i < 10; i++) {
        if (arr[i] > 1) {
            return false;
        }
    }

    return true;
}


void solve(int board[9][9], int row, int col, int size) {
    if (col == size) {
        row++;
        col = 0;
    }
    if (row == size) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "------------------------------------------------------------------------------------------" << endl;
        return;
    }

    if (board[row][col] == 0) {
        for (int i = 1; i <= 9; i++) {
            board[row][col] = i;
            if (check(board, row, col)) {
                solve(board, row, col + 1, size);
            }
            board[row][col] = 0; // Reset the cell to 0 for backtracking
        }
    } else {
        solve(board, row, col + 1, size);
    }
}


int main()
{
    int board[9][9] = {
        {7, 0, 0, 0, 0, 3, 0, 0, 0},
        {0, 3, 4, 6, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 8, 0, 0, 2, 0},
        {0, 9, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 5, 3, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 6, 3, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 5, 7, 0, 0, 2, 0, 1, 0},
        {9, 0, 0, 5, 0, 0, 0, 0, 0}};

    int row = 0;
    int col = 0;
    int size = 9;

    solve(board, row, col, size);

}