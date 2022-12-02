#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e8

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> dp(m, 0);
    vector<int> row(m, 0);

    for (int i = 0; i < m; i++)
        dp[i] = matrix[0][i];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int left, up, right;
            left = up = right = matrix[i][j];
            if (j > 0)
                left += dp[j - 1];
            else
                left = INT_MIN;
            up += dp[j];
            if (j < m - 1)
                right += dp[j + 1];
            else
                right = INT_MIN;

            row[j] = max(up, max(left, right));
        }
        dp = row;
    }

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        int curr = dp[j];
        maxi = max(maxi, curr);
    }

    return maxi;
}

int main()
{

    return 0;
}