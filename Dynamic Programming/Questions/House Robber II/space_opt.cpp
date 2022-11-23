#include <iostream>
#include <vector>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    int prev2 = 0, prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;
        int dont = prev1;

        int curr = max(pick, dont);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    vector<int> temp1, temp2;
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

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

// T.C : O(N) and S.C : O(1)