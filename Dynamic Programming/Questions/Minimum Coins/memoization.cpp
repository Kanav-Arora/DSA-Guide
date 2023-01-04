#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &num, int ind, int x, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (x % num[0] == 0)
        {
            return x / num[0];
        }
        else
            return 1e9;
    }

    if (dp[ind][x] != -1)
        return dp[ind][x];

    int nottake = solve(num, ind - 1, x, dp);
    int take = 1e9;
    if (num[ind] <= x)
        take = 1 + solve(num, ind, x - num[ind], dp);
    return dp[ind][x] = min(nottake, take);
}

int minimumElements(vector<int> &num, int x)
{
    vector<vector<int>> dp(num.size(), vector<int>(x + 1, -1));
    int val = solve(num, num.size() - 1, x, dp);

    return val == 1e9 ? -1 : val;
}

int main()
{

    return 0;
}