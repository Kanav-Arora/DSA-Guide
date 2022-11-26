#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int> &nums, int i)
{
    if (i >= nums.size())
        return false;
    if (i == nums.size() - 1)
        return true;

    int curr = nums[i];
    bool ans = false;
    for (int step = 1; step <= curr; step++)
    {
        ans = ans || solve(nums, i + step);
    }

    return ans;
}

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    return solve(nums, 0);
}

int main()
{

    return 0;
}