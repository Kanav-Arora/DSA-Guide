#include <iostream>
#include <vector>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = dp[ind - 1][target];
            bool take = false;
            if (target >= arr[ind])
                take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take || nottake;
        }
    }

    return dp[n - 1][k];
}

int main()
{

    return 0;
}