#include <bits/stdc++.h>
using namespace std;

void solve(int board[4][4], int visited[4][4], int row, int col, string &ans, int size){
    if(row==size-1 && col==size-1){
        cout << ans << endl;
        return;
    }

    if(row-1>=0 && visited[row-1][col]==0 && board[row-1][col]==1){
        visited[row-1][col]=1;
        ans.push_back('U');
        solve(board, visited, row-1, col, ans, size);
        visited[row-1][col]=0;
        ans.pop_back();
    }
    if(col+1<size && visited[row][col+1]==0 && board[row][col+1]==1){
        visited[row][col+1]=1;
        ans.push_back('R');
        solve(board, visited, row, col+1, ans, size);
        visited[row][col+1]=0;
        ans.pop_back();
    }
    if(row+1<size && visited[row+1][col]==0 && board[row+1][col]==1){
        visited[row+1][col]=1;
        ans.push_back('D');
        solve(board, visited, row+1, col, ans, size);
        visited[row+1][col]=0;
        ans.pop_back();
    }
    if(col-1>=0 && visited[row][col-1]==0 && board[row][col-1]==1){
        visited[row][col-1]=1;
        ans.push_back('L');
        solve(board, visited, row, col-1, ans, size);
        visited[row][col-1]=0;
        ans.pop_back();
    }
    return;
}

int main(){
    int board[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    int visited[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int row = 0;
    int col = 0;
    string ans = "";
    int size = 4;
    solve(board, visited, row, col, ans, size);

}