#include <iostream>
#include <vector>
using namespace std;

/*
    Tabulation code on Leetcode gives a integer overflow for long long and long long int
    so we needed to use double for tabulation table and then type cast it
    to int for submission.
*/

int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return (int)dp[n][m];
}

int main()
{

    return 0;
}