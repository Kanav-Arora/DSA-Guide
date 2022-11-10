#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> pr;

int MinimumEffort(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, {0, 0}});

    int drow[] = {0, -1, 0, 1};
    int dcol[] = {-1, 0, 1, 0};

    while (!pq.empty())
    {
        auto front = pq.top();
        int diff = front.first;
        int i = front.second.first;
        int j = front.second.second;

        pq.pop();

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                int cost = max(abs(heights[nrow][ncol] - heights[i][j]), diff);

                if (cost < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = cost;
                    pq.push({cost, {nrow, ncol}});
                }
            }
        }
    }

    return dist[n - 1][m - 1];
}

int main()
{

    return 0;
}