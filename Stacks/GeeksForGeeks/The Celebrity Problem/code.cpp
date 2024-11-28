#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }
        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (mat[a][b] == 1)
                st.push(b);
            else if (mat[b][a] == 1)
                st.push(a);
        }
        if (st.empty())
            return -1;
        int ans = st.top();
        for (int i = 0; i < n; i++)
        {
            if (i != ans)
            {
                if (mat[ans][i] == 1 || mat[i][ans] == 0)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};