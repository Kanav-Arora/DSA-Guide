// GFG

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<vector<char>> grid, int i, int j, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();

        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int nrow = front.first + delrow;
                int ncol = front.second + delcol;

                if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int counter = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                counter++;
                BFS(grid, i, j, visited);
            }
        }
    }

    return counter;
}

int main()
{

    return 0;
}