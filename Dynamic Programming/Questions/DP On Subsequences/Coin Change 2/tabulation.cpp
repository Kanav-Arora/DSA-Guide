#include <iostream>
#include <vector>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int i = 0; i <= value; i++)
    {
        if (i % denominations[0] == 0)
            dp[0][i] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int val = 0; val <= value; val++)
        {
            long notpick = dp[ind - 1][val];
            long pick = 0;
            if (denominations[ind] <= val)
                pick = dp[ind][val - denominations[ind]];
            dp[ind][val] = notpick + pick;
        }
    }

    return dp[n - 1][value];
}

int main()
{

    return 0;
}