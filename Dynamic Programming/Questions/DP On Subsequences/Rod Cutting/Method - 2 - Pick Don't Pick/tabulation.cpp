#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    for(int N = 0; N<=n; N++)
    {
        dp[0][N] = N*price[0];
    }

    for(int ind = 1; ind<n; ind++)
    {
        for(int N = 0; N<=n; N++)
        {
            int nottake = dp[ind-1][N];
            int take = INT_MIN;
            int rest = ind+1;

            if(rest<=N)
                take = price[ind] + dp[ind][N-rest];
            dp[ind][N] = max(take,nottake);
        }
    }

    return dp[n-1][n];
}

int main()
{

    return 0;
}