#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<string> ans;
        if (n == 0)
            return ans;

        int start = 0;

        for (int curr = 1; curr < n; ++curr)
        {
            if (nums[curr] != nums[curr - 1] + 1)
            {
                if (start == curr - 1)
                {
                    ans.push_back(to_string(nums[start]));
                }
                else
                {
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[curr - 1]));
                }
                start = curr;
            }
        }

        if (start == n - 1)
        {
            ans.push_back(to_string(nums[start]));
        }
        else
        {
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums[n - 1]));
        }

        return ans;
    }
};
