#include<iostream>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;

int dp[100000];

int frogJump(int n, vector<int> &heights)
{
    memset(dp,-1,sizeof(dp));
    dp[0] = 0, dp[1] = fabs(heights[1]-heights[0]);
    
    for(int i=2; i<n; i++)
    {
        dp[i] = min(dp[i-1] + fabs(heights[i]-heights[i-1]),
                   dp[i-2] + fabs(heights[i] - heights[i-2]));
    }
    
    return dp[n-1];
}

int main()
{
    
    return 0;
}