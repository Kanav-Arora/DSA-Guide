#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp)
{
    if (i == triangle.size() - 1)
        return triangle[triangle.size() - 1][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int curr = triangle[i][j];
    int down = curr + solve(triangle, i + 1, j, dp);
    int diag = curr + solve(triangle, i + 1, j + 1, dp);
    return dp[i][j] = min(down, diag);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));

    return solve(triangle, 0, 0, dp);
}

int main()
{

    return 0;
}