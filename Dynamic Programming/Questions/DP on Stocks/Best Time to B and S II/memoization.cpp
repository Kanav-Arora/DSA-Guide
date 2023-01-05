#include <iostream>
#include <vector>
using namespace std;

long solver(long *v, int n, vector<vector<long>> &dp, int index, bool buy)
{
    if (index == n)
    {
        return 0;
    }

    if (dp[index][buy] != -1)
        return dp[index][buy];

    long profit = 0;
    if (buy)
    {
        long take = -v[index] + solver(v, n, dp, index + 1, 0);
        long nottake = 0 + solver(v, n, dp, index + 1, 1);

        profit = max(take, nottake);
    }
    else
    {
        long sell = v[index] + solver(v, n, dp, index + 1, 1);
        long notsell = 0 + solver(v, n, dp, index + 1, 0);

        profit = max(sell, notsell);
    }
    return dp[index][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return solver(values, n, dp, 0, 1);
}

int main()
{

    return 0;
}