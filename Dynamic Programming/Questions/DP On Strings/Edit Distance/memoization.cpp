#include <iostream>
#include <vector>
using namespace std;

// Memoization solution might raise TLE on both the platforms

class Solution
{
private:
    int solver(string word1, string word2, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return 0 + solver(word1, word2, i - 1, j - 1, dp);

        int insert = 1 + solver(word1, word2, i, j - 1, dp);
        int del = 1 + solver(word1, word2, i - 1, j, dp);
        int replace = 1 + solver(word1, word2, i - 1, j - 1, dp);
        return dp[i][j] = min(insert, min(del, replace));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solver(word1, word2, n - 1, m - 1, dp);
    }
};

int main()
{

    return 0;
}