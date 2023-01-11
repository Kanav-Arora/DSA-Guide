#include <iostream>
#include <vector>
using namespace std;

bool solver(string pattern, string text, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0)
        return false;
    if (j < 0)
    {
        for (int m = 0; m <= i; m++)
            if (pattern[m] != '*')
                return false;
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return dp[i][j] = solver(pattern, text, i - 1, j - 1, dp);
    }
    if (pattern[i] == '*')
        return dp[i][j] = solver(pattern, text, i, j - 1, dp) || solver(pattern, text, i - 1, j, dp);
    return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length();
    int m = text.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solver(pattern, text, n - 1, m - 1, dp);
}

int main()
{

    return 0;
}