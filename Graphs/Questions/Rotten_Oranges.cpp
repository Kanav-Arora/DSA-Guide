// GFG: Rotten Oranges

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    int time = 0;
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            pair<int, int> front = q.front();
            q.pop();
            int r = front.first;
            int c = front.second;

            if (r - 1 >= 0 && grid[r - 1][c] == 1)
            {
                grid[r - 1][c] = 2;
                q.push({r - 1, c});
            }
            if (r + 1 < n && grid[r + 1][c] == 1)
            {
                grid[r + 1][c] = 2;
                q.push({r + 1, c});
            }
            if (c - 1 >= 0 && grid[r][c - 1] == 1)
            {
                grid[r][c - 1] = 2;
                q.push({r, c - 1});
            }
            if (c + 1 < m && grid[r][c + 1] == 1)
            {
                grid[r][c + 1] = 2;
                q.push({r, c + 1});
            }
        }

        time++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    return time - 1;
}

int main()
{

    return 0;
}