#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &num, int tar, int ind, vector<vector<int>> &dp)
{
    if (tar == 0)
        return 1;
    if (ind == 0)
        return tar == num[0];
    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    int nottake = solve(num, tar, ind - 1, dp);
    int take = 0;
    if (tar >= num[ind])
        take = solve(num, tar - num[ind], ind - 1, dp);
    return dp[ind][tar] = take + nottake;
}

int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar + 1, -1));
    return solve(num, tar, num.size() - 1, dp);
}

int main()
{

    return 0;
}