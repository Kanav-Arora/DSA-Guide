#include <iostream>
#include <vector>
using namespace std;

int max(int v1, int v2)
{
    return v1 < v2 ? v2 : v1;
}

int lcs(string s, string t)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
    int ans = 0;
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return ans;
}

int main()
{

    return 0;
}