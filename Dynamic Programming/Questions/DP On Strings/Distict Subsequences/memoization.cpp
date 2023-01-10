#include <iostream>
#include <vector>
using namespace std;

int solver(string t, string s, int lt, int ls, vector<vector<int>> &dp)
{
    if (ls < 0)
        return 1;
    if (lt < 0)
        return 0;

    if (dp[lt][ls] != -1)
        return dp[lt][ls];

    if (t[lt] == s[ls])
        return dp[lt][ls] = solver(t, s, lt - 1, ls - 1, dp) + solver(t, s, lt - 1, ls, dp);
    else
        return dp[lt][ls] = solver(t, s, lt - 1, ls, dp);
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return solver(t, s, lt - 1, ls - 1, dp);
}

int main()
{

    return 0;
}