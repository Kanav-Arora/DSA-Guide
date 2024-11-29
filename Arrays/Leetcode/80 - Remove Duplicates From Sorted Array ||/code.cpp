#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
            return n;
        int first = 1, second = 0;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] != nums[second])
            {
                first++;
                second++;
                nums[first] = nums[i];
            }
        }
        return first + 1;
    }
};