#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[10001];

bool solve(vector<int> &nums, int i)
{

    if (i >= nums.size())
        return false;
    if (i == nums.size() - 1)
        return true;

    if (dp[i] != -1)
        return dp[i] == 1;

    int curr = nums[i];
    bool ans = false;
    for (int step = 1; step <= curr; step++)
    {
        ans = ans || solve(nums, i + step);
    }

    ans == true ? dp[i] = 1 : dp[i] = 0;

    return ans;
}

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(nums, 0);
}

int main()
{

    return 0;
}