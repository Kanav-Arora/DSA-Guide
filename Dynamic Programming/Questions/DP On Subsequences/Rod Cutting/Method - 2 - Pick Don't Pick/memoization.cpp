#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int solve(vector<int> &price, int ind, int len, vector<vector<int>> &dp)
{
    if(ind==0)  return len*price[0];
    if(dp[ind][len]!=-1)    return dp[ind][len];

    int nottake = 0 + solve(price,ind-1,len,dp);
    int take = INT_MIN;
    int rest = ind+1;

    if(rest<=len)
        take = price[ind] + solve(price,ind,len-rest,dp);

    return dp[ind][len] = max(take,nottake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1,-1));
    return solve(price, n-1, n, dp);
}

int main()
{

    return 0;
}