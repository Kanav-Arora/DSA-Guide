#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        if (n == 0)
            return ans;
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> temp = intervals[0];

        for (int i = 1; i < n; i++)
        {
            vector<int> &inv = intervals[i];
            if (inv[0] >= temp[0] && inv[0] <= temp[1])
            {
                temp[1] = max(temp[1], inv[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = inv;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};