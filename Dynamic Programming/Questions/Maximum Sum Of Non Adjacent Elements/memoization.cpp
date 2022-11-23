#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[1001];

int solve(vector<int> &nums, int i)
{
    if(i<0)    return 0;
    if(i==0)    return nums[0];
    
    if(dp[i]!=-1)    return dp[i];
    
    int pick = nums[i] + solve(nums,i-2);
    int notpick = solve(nums,i-1);
    
    return dp[i] = max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    memset(dp,-1,sizeof(dp));
    return solve(nums,nums.size()-1);
}

int main()
{

    return 0;
}