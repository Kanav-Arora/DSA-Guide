#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> st; // pair<index,value>
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int ele = temperatures[i];
            while (!st.empty() && ele >= st.top().second)
            {
                st.pop();
            }
            if (!st.empty())
                ans[i] = st.top().first - i;
            st.push({i, ele});
        }
        return ans;
    }
};