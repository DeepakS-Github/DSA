#include <iostream>
using namespace std;

void getAns(int board[4][4], int size)
{
    for (int col = 0; col < size; col++)
    {
        for (int row = 0; row < size; row++)
        {
            if (board[row][col] == 1)
            {
                cout << row;
            }
        }
    }
    cout << endl;
}

bool isSafe(int board[4][4], int row, int col, int size)
{
    for (int i = col - 1; i >= 0; i--){
        if (board[row][i] == 1){
            return false;
        }
    }

    int i=row;
    int j=col;
    while (i>=0 && j>=0){
        i--;
        j--;
        if (board[i][j] == 1){
            return false;
        }
    }

    i=row;
    j=col;
    while (i < size && j >= 0){
        i++;
        j--;
        if (board[i][j] == 1){
            return false;
        }
    }

    return true;
}




void solve(int board[4][4], int row, int col, int size)
{
    if (col == size)
    {
        getAns(board, size);
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (isSafe(board, i, col, size))
        {
            board[i][col] = 1;
            solve(board, i, col + 1, size);
            board[i][col] = 0;
        }
    }
    return;
}

int main()
{
    int board[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int row = 0;
    int col = 0;
    int size = 4;
    solve(board, row, col, size);
}