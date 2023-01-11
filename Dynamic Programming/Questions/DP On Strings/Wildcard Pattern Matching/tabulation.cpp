#include <iostream>
#include <vector>
using namespace std;

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length();
    int m = text.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= m; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[i - 1] == '*')
                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

int main()
{

    return 0;
}