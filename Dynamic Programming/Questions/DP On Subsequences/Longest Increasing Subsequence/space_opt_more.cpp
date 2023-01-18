#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int max(int a, int b)
    {
        return a < b ? b : a;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int maxi = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    maxi = max(dp[j] + dp[i], maxi);
            }
            dp[i] = maxi;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}