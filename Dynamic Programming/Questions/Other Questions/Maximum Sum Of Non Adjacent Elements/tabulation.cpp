#include <iostream>
#include <vector>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];

    for(int i=1; i<n; i++)
    {
        int pick = nums[i];
        if(i>1)
            pick+=dp[i-2];
        int dont = dp[i-1];

        dp[i]  = max(pick,dont);
    }

    return dp[n-1];
}

int main()
{

    return 0;
}

// T.C : O(N) and S.C : O(N)