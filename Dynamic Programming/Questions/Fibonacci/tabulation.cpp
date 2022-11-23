#include<iostream>
#include <cstring>
using namespace std;

int main()
{
    int dp[1000];
    memset(dp,-1,sizeof(dp));

    dp[0] = 1, dp[1] = 1;
    
    int n;
    cin>>n;

    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    cout<<dp[n]<<endl;

    return 0;
}

// T.C : O(N) and S.C : O(N)