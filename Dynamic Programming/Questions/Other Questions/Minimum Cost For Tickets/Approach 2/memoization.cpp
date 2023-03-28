#include <iostream>
#include <vector>
using namespace std;

int solver(int n, vector<int> &days, int ind, vector<int> &costs, vector<int> &dp)
{
    if (ind >= n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int call1 = costs[0] + solver(n, days, ind + 1, costs, dp);
    int i;
    for (i = ind; i < n && days[i] < days[ind] + 7; i++)
        ;
    int call2 = costs[1] + solver(n, days, i, costs, dp);
    for (i = ind; i < n && days[i] < days[ind] + 30; i++)
        ;
    int call3 = costs[2] + solver(n, days, i, costs, dp);

    return dp[ind] = min(call1, min(call2, call3));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n, -1);
    return solver(n, days, 0, costs, dp);
}

int main()
{

    return 0;
}