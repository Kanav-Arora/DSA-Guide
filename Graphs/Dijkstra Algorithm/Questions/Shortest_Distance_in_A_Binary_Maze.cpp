#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;
    queue<pair<int, int>> q;
    q.push(source);

    int ans = 0;
    while (!q.empty())
    {
        int size = q.size();

        while (size-- > 0)
        {
            auto front = q.front();
            q.pop();

            int i = front.first;
            int j = front.second;

            int drow[] = {0, -1, 0, 1};
            int dcol[] = {-1, 0, 1, 0};

            for (int k = 0; k < 4; k++)
            {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];

                if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 && dist[nrow][ncol] > dist[i][j] + 1)
                {
                    q.push({nrow, ncol});
                    dist[nrow][ncol] = dist[i][j] + 1;
                }
            }
        }
    }

    int i = destination.first;
    int j = destination.second;

    return dist[i][j] == 1e9 ? -1 : dist[i][j];
}

int main()
{

    return 0;
}