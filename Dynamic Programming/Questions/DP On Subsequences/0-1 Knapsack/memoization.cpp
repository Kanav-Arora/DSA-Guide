#include <iostream>
#include <vector>
using namespace std;

int solver(vector<int> weight, vector<int> value, int ind, int wt, vector<vector<int>> &dp)
{
    if (wt == 0)
        return 0;
    if (ind == 0)
        return wt >= weight[0] ? value[0] : 0;

    if (dp[ind][wt] != -1)
        return dp[ind][wt];

    int notpick = solver(weight, value, ind - 1, wt, dp);
    int pick = 0;
    if (wt >= weight[ind])
        pick = value[ind] + solver(weight, value, ind - 1, wt - weight[ind], dp);

    return dp[ind][wt] = max(pick, notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solver(weight, value, n - 1, maxWeight, dp);
}

int main()
{

    return 0;
}