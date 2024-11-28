#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int MAH(vector<int> &heights, int n)
    {
        stack<int> st;
        int maxA = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix[0].size();
        vector<int> inputs(n, 0);
        int maxArea = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                inputs[j] = (matrix[i][j] == '1') ? inputs[j] + 1 : 0;
            }
            maxArea = max(maxArea, MAH(inputs, n));
        }
        return maxArea;
    }
};
