#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(nums.size(), 0);
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int ele = nums[i % n];
            while (!st.empty() && ele >= st.top())
            {
                st.pop();
            }
            if (i < n)
            {
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(ele);
        }
        return ans;
    }
};