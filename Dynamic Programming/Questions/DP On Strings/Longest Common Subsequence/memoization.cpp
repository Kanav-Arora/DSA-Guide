#include <iostream>
#include <vector>
using namespace std;

int solver(string s, string t, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s[ind1] == t[ind2])
        return dp[ind1][ind2] = 1 + solver(s, t, ind1 - 1, ind2 - 1, dp);
    else
        return dp[ind1][ind2] = 0 + max(solver(s, t, ind1 - 1, ind2, dp), solver(s, t, ind1, ind2 - 1, dp));
}

int lcs(string s, string t)
{
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    return solver(s, t, s.length() - 1, t.length() - 1, dp);
}

int main()
{

    return 0;
}