#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int solve(vector<int> &price, int len, vector<int> &dp)
{
    if (len == 0)
        return 0;
    int maxi = INT_MIN;
    if (dp[len] != -1)
        return dp[len];
    for (int i = 1; i <= price.size(); i++)
    {
        if (i <= len)
        {
            int call = solve(price, len - i, dp) + price[i - 1];
            maxi = maxi > call ? maxi : call;
        }
    }

    return dp[len] = maxi;
}

int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n + 1, -1);
    return solve(price, n, dp);
}

int main()
{

    return 0;
}