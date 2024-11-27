#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<pair<int, int>> st; // index, value

        for (int i = 0; i < n; i++)
        {
            int ele = heights[i];
            while (!st.empty() && st.top().second >= ele)
                st.pop();
            if (st.empty())
                left[i] = 0;
            else
                left[i] = st.top().first + 1;
            st.push({i, ele});
        }

        stack<pair<int, int>> st2; // index, value

        for (int i = n - 1; i >= 0; i--)
        {
            int ele = heights[i];
            while (!st2.empty() && st2.top().second >= ele)
                st2.pop();
            if (st2.empty())
                right[i] = n - 1;
            else
                right[i] = st2.top().first - 1;
            st2.push({i, ele});
        }

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int height = heights[i];
            int area = (right[i] - left[i] + 1) * height;
            maxi = max(maxi, area);
        }

        return maxi;
    }
};
