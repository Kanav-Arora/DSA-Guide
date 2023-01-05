#include <iostream>
#include <vector>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    for (int i = 0; i <= w; i++)
        dp[0][i] = i >= weight[0] ? (i / weight[0]) * profit[0] : 0;

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int nottake = dp[ind - 1][wt];
            int take = -1e9;
            if (wt >= weight[ind])
                take = profit[ind] + dp[ind][wt - weight[ind]];

            dp[ind][wt] = max(take, nottake);
        }
    }

    return dp[n - 1][w];
}

int main()
{

    return 0;
}