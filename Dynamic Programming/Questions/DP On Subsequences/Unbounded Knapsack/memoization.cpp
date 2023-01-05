#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &profit, vector<int> &weight, int ind, int w, vector<vector<int>> &dp)
{
    if (w == 0)
        return 0;
    if (ind == 0)
    {
        if (w >= weight[0])
            return (w / weight[0]) * profit[0];
        else
            return 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];

    int nottake = solve(profit, weight, ind - 1, w, dp);
    int take = -1e9;
    if (w >= weight[ind])
        take = profit[ind] + solve(profit, weight, ind, w - weight[ind], dp);

    return dp[ind][w] = max(take, nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(profit, weight, n - 1, w, dp);
}

int main()
{

    return 0;
}