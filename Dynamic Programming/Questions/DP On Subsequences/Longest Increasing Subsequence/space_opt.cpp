#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int dont = next[prev + 1];
                int pick = 0;
                if (prev == -1 || nums[i] > nums[prev])
                {
                    pick = 1 + next[i + 1];
                }
                curr[prev + 1] = max(pick, dont);
            }
            next = curr;
        }

        return next[0];
    }
};

int main()
{

    return 0;
}