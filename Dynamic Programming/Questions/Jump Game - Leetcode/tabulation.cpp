#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int dp[n];
    memset(dp,0,sizeof(dp));

    dp[0] = true;

    for(int i=1; i<n; i++)
    {
        for(int step=i-1; step>=0; step--)
        {
            if(dp[step] && step>=i-nums[step])
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n-1];

}

int main()
{
    
    return 0;
}