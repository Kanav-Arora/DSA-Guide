#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int i)
{
    if (i < 0)
        return 0;
    if (i == 0)
        return nums[0];
    int pick = nums[i] + solve(nums, i - 2);
    int notpick = solve(nums, i - 1);

    return max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    return solve(nums, nums.size() - 1);
}

int main()
{

    return 0;
}