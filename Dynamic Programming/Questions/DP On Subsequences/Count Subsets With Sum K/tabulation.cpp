#include <iostream>
#include <vector>
using namespace std;

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int k = 0; k <= tar; k++)
        {
            int nottake = dp[ind - 1][k];
            int take = 0;
            if (k >= num[ind])
                take = dp[ind - 1][k - num[ind]];
            dp[ind][k] = take + nottake;
        }
    }
    return dp[n - 1][tar];
}

int main()
{

    return 0;
}