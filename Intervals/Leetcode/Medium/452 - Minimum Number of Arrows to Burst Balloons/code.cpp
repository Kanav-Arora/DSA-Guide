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

    int findMinArrowShots(vector<vector<int>> &points)
    {
        vector<vector<int>> ans;
        int n = points.size();
        if (n == 0)
            return 0;
        sort(points.begin(), points.end(), comp);
        vector<int> temp = points[0];

        for (int i = 1; i < n; i++)
        {
            vector<int> &inv = points[i];
            if (inv[0] >= temp[0] && inv[0] <= temp[1])
            {
                temp[0] = max(temp[0], inv[0]);
                temp[1] = min(temp[1], inv[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = inv;
            }
        }
        ans.push_back(temp);
        return ans.size();
    }
};