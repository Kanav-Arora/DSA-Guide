#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool solver(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &dp)
    {
        if (k == s3.length() && i == s1.length() && j == s2.length())
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];

        bool c1 = false, c2 = false;
        if (i != s1.length() && s1[i] == s3[k])
            c1 = solver(s1, s2, s3, i + 1, j, k + 1, dp);
        if (j != s2.length() && s2[j] == s3[k])
            c2 = solver(s1, s2, s3, i, j + 1, k + 1, dp);
        return dp[i][j] = c1 || c2;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        // we took one bigger index for the last call because we are return dp before checking for last index at line 16 and 18
        return solver(s1, s2, s3, 0, 0, 0, dp);
    }
};

int main()
{

    return 0;
}