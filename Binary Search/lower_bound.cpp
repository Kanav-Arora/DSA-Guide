#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int> nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = 0;
    int ans = 0;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(6);
    nums.push_back(8);
    nums.push_back(11);
    cout << lower_bound(nums, 6);
    return 0;
}