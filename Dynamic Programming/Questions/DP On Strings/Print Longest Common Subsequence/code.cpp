#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> lcs(string s, string t)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << "Length of LCS: " << dp[s.length()][t.length()] << endl;
    return dp;
}

int main()
{
    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp = lcs(s, t);

    int n = dp.size();
    int m = dp[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    string sub = "";

    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            sub = s[i - 1] + sub;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }

    cout << "LCS: " << sub << endl;
    return 0;
}