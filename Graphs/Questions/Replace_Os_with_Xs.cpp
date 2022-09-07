#include <iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<char>> mat, int r, int c, vector<vector<bool>> &marked)
{
    marked[r][c] = false;

    int rowd[] = {-1, 0, 1, 0};
    int cold[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = r + rowd[i];
        int ncol = c + cold[i];

        if (nrow >= 0 && nrow < mat.size() && ncol >= 0 && ncol < mat[0].size() && mat[nrow][ncol] == 'O' && marked[nrow][ncol] == true)
        {
            DFS(mat, nrow, ncol, marked);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<bool>> marked(n, vector<bool>(m, true));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'X')
                marked[i][j] = false;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (mat[0][j] == 'O' && marked[0][j] == true)
        {
            DFS(mat, 0, j, marked);
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (mat[n - 1][j] == 'O' && marked[n - 1][j] == true)
        {
            DFS(mat, n - 1, j, marked);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 'O' && marked[i][0] == true)
        {
            DFS(mat, i, 0, marked);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (mat[i][m - 1] == 'O' && marked[i][m - 1] == true)
        {
            DFS(mat, i, m - 1, marked);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (marked[i][j] == true)
                mat[i][j] = 'X';
        }
    }

    return mat;
}

int main()
{

    return 0;
}