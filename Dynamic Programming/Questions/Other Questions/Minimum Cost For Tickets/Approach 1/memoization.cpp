#include <iostream>
#include <vector>
using namespace std;

int solver(vector<int> &days, int ind, int d, vector<int> &costs, vector<vector<int>> &dp)
{
    if (ind == days.size())
        return 0;
    if (dp[ind][d] != -1)
        return dp[ind][d];
    if (days[ind] <= d)
        return dp[ind][d] = solver(days, ind + 1, d, costs, dp);
    int call1 = costs[0] + solver(days, ind + 1, days[ind], costs, dp);
    int call2 = costs[1] + solver(days, ind + 1, days[ind] + 6, costs, dp);
    int call3 = costs[2] + solver(days, ind + 1, days[ind] + 29, costs, dp);

    return dp[ind][d] = min(call1, min(call2, call3));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<vector<int>> dp(n, vector<int>(days[n - 1] + 30, -1));
    return solver(days, 0, 0, costs, dp);
}

int main()
{
    return 0;
}