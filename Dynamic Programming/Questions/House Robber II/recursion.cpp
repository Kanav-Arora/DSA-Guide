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