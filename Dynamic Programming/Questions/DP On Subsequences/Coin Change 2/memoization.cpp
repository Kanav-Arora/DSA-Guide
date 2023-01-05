#include <iostream>
#include <vector>
using namespace std;

long solve(int *den, int ind, int val, vector<vector<long>> &dp)
{
    if (val == 0)
        return 1;
    if (ind == 0)
    {
        if (val % den[0] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[ind][val] != -1)
        return dp[ind][val];

    long notpick = solve(den, ind - 1, val, dp);
    long pick = 0;
    if (den[ind] <= val)
        pick = solve(den, ind, val - den[ind], dp);
    return dp[ind][val] = notpick + pick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return solve(denominations, n - 1, value, dp);
}

int main()
{

    return 0;
}