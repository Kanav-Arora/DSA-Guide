#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int srow = 0, scol = 0;
        int maxKeys = 0;

        // we must find the total number of keys we are looking for
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '@')
                {
                    srow = i;
                    scol = j;
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                {
                    maxKeys = max((grid[i][j] - 'a') + 1, maxKeys);
                }
            }
        }
        vector<int> start = {0, srow, scol};
        queue<vector<int>> q;
        unordered_set<string> vis;
        vis.insert(to_string(0) + " " + to_string(srow) + " " + to_string(scol));
        q.push(start);
        int step = 0;
        int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!q.empty())
        {
            int k = q.size();
            for (int i = 0; i < k; i++)
            {
                auto curr = q.front();
                q.pop();
                if (curr[0] == (1 << maxKeys) - 1)
                {
                    return step;
                }
                for (auto &d : dir)
                {
                    int nrow = curr[1] + d[0];
                    int ncol = curr[2] + d[1];
                    int keys = curr[0];

                    if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n)
                    {
                        char c = grid[nrow][ncol];
                        if (c == '#')
                            continue;
                        if (c >= 'a' && c <= 'f')
                            keys |= 1 << (c - 'a');
                        if (c >= 'A' && c <= 'F' && (((keys >> (c - 'A')) & 1) == 0))
                            continue;
                        if (!vis.count(to_string(keys) + " " + to_string(nrow) + " " + to_string(ncol)))
                        {
                            vis.insert(to_string(keys) + " " + to_string(nrow) + " " + to_string(ncol));
                            q.push({keys, nrow, ncol});
                        }
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};

int main()
{

    return 0;
}