#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define maxi 1e9

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(m,0);
    vector<int> curr(m,0);
    curr[0] = grid[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[0] = grid[0][0];
            else
            {
                int left = grid[i][j], up = grid[i][j];

                if (i > 0)
                    up += prev[j];
                else
                    up = maxi;

                if (j > 0)
                    left += curr[j-1];
                else
                    left = maxi;

                curr[j] = min(up, left);
            }
        }

        prev = curr;
    }

    return prev[m-1];
}

int main()
{

    return 0;
}