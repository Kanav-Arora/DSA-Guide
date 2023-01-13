#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int solver(string t, string s, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (t[i] == s[j])
            return dp[i][j] = 1 + solver(t, s, i - 1, j - 1, dp);
        else
            return dp[i][j] = max(solver(t, s, i - 1, j, dp), solver(t, s, i, j - 1, dp));
    }

public:
    bool isSubsequence(string s, string t)
    {
        vector<vector<int>> dp(t.length(), vector<int>(s.length(), -1));
        int ans = solver(t, s, t.length() - 1, s.length() - 1, dp);
        return ans == s.length();
    }
};

int main()
{

    return 0;
}