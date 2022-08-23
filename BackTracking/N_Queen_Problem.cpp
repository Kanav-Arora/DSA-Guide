#include <iostream>
#include <vector>
using namespace std;

void addSolution(vector<vector<int>> &board, int n, vector<vector<int>> &ans)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y= col;

    while(y>=0)
    {
        if(board[x][y]==1)
            return false;
        y--;
    }

    x = row;
    y = col;

    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
            return false;
        
        x--;
        y--;
    }

    x = row;
    y = col;

    while(x<n && y>=0)
    {
        if(board[x][y]==1)
            return false;
        
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    if (col == n)
    {
        addSolution(board, n, ans);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(i,col, board, n))
        {
            board[i][col] = 1;
            solve(col+1, board,ans,n);
            board[i][col] = 0;
        }
    }
}

vector<vector<int>> NQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, board, ans, n);

    return ans;
}

int main()
{

    return 0;
}