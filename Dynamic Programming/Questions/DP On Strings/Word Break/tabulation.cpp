#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--)
        {
            int ans = false;
            string temp;
            for (int j = i; j < n; j++)
            {
                temp += s[j];
                if (st.find(temp) != st.end())
                {
                    ans = dp[j + 1];
                    if (ans == true)
                    {
                        break;
                    }
                }
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};

int main()
{

    return 0;
}