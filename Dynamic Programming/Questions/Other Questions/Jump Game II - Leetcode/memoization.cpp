#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[10001];
int solve(vector<int> &nums, int i)
{
    if (i >= nums.size() - 1)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int mini = 1e5;
    for (int step = 1; step <= nums[i]; step++)
    {
        mini = min(mini, solve(nums, i + step));
    }

    return dp[i] = 1 + mini;
}

int jump(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    return solve(nums, 0);
}

int main()
{

    return 0;
}