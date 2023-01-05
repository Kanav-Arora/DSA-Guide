#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return numeric_limits<int>::max();
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] + min(solve(grid, i, j - 1, dp), solve(grid, i - 1, j, dp));
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    solve(grid, n - 1, m - 1, dp);
    return dp[n - 1][m - 1];
}

int main()
{

    return 0;
}