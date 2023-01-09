#include <iostream>
#include <vector>
using namespace std;

string lcs(string s, string t)
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

    int n = dp.size();
    int m = dp[0].size();

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

    return sub;
}

int main()
{
    string s;
    cin >> s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    cout << lcs(s, s2);
    return 0;
}