// GFG: Number of Enclaves

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &marked)
{
    marked[r][c] = true;

    int rowd[] = {-1, 0, 1, 0};
    int cold[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = r + rowd[i];
        int ncol = c + cold[i];

        if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 && marked[nrow][ncol] == false)
        {
            DFS(grid, nrow, ncol, marked);
        }
    }
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> marked(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1 && marked[i][0] == false)
            DFS(grid, i, 0, marked);

        if (grid[i][m - 1] == 1 && marked[i][m - 1] == false)
            DFS(grid, i, m - 1, marked);
    }

    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 1 && marked[0][j] == false)
            DFS(grid, 0, j, marked);

        if (grid[n - 1][j] == 1 && marked[n - 1][j] == false)
            DFS(grid, n - 1, j, marked);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (marked[i][j] == true)
            {
                grid[i][j] = 0;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}