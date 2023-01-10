#include <iostream>
#include <vector>
using namespace std;

string shortestSupersequence(string s, string t)
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

    string sub = "";

    int i = s.length(), j = t.length();

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            sub += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            sub += s[i - 1];
            i--;
        }
        else
        {
            sub += t[j - 1];
            j--;
        }
    }

    while (i > 0)
    {
        sub += s[i - 1];
        i--;
    }
    while (j > 0)
    {
        sub += t[j - 1];
        j--;
    }

    reverse(sub.begin(), sub.end());
    return sub;
}

int main()
{
    string s = "brute";
    string t = "groot";
    cout << shortestSupersequence(s, t) << endl;
    return 0;
}