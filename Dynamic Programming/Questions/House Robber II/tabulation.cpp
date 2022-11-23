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

long long int houseRobber(vector<int> &valueInHouse)
{
    vector<int> temp1, temp2;
    int n = valueInHouse.size();
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }

    int ans1 = maximumNonAdjacentSum(temp1);
    int ans2 = maximumNonAdjacentSum(temp2);

    return max(ans1, ans2);
}

int main()
{

    return 0;
}

// T.C : O(N) and S.C : O(N)