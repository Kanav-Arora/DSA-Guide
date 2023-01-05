#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int i = weight[0]; i <= maxWeight; i++)
        dp[0][i] = value[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int notpick = dp[ind - 1][wt];
            int pick = INT_MIN;
            if (wt >= weight[ind])
                pick = value[ind] + dp[ind - 1][wt - weight[ind]];
            dp[ind][wt] = max(pick, notpick);
        }
    }

    return dp[n - 1][maxWeight];
}

int main()
{

    return 0;
}