#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> dp(n);
    for (int j = 0; j < n; j++)
        dp[j] = triangle[n - 1][j];

    vector<int> row(n,-1);
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int curr = triangle[i][j];
            int down = curr + dp[j];
            int diag = curr + dp[j + 1];

            row[j] = min(down, diag);
        }
        dp = row;
    }

    return dp[0];
}

int main()
{

    return 0;
}