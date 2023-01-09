#include <iostream>
#include <vector>
using namespace std;

int max(int v1, int v2)
{
    return v1 < v2 ? v2 : v1;
}

int solver(string s1, string s2, int i, int j, vector<vector<int>> &dp, int &ans)
{
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int l = solver(s1, s2, i - 1, j, dp, ans);
    int k = solver(s1, s2, i, j - 1, dp, ans);

    if (s1[i - 1] == s2[j - 1])
    {
        dp[i][j] = solver(s1, s2, i - 1, j - 1, dp, ans) + 1;
        ans = max(ans, dp[i][j]);
        return dp[i][j];
    }
    return dp[i][j] = 0;
}

int lcs(string &str1, string &str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;
    int v = solver(str1, str2, n, m, dp, ans);

    return ans;
}

int main()
{

    return 0;
}