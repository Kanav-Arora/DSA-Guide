#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define maxi 1e9

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int left = grid[i][j], up = grid[i][j];

                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up = maxi;

                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left = maxi;

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{

    return 0;
}