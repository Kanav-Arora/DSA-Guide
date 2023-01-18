#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int solver(vector<int> &nums, int i, int prev, vector<vector<int>> &dp)
    {
        if (i < 0)
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int dont = solver(nums, i - 1, prev, dp);
        int pick = 0;
        if (prev == -1 || nums[i] < nums[prev])
            pick = 1 + solver(nums, i - 1, i, dp);
        return dp[i][prev + 1] = max(pick, dont);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solver(nums, n - 1, -1, dp);
    }
};

int main()
{

    return 0;
}