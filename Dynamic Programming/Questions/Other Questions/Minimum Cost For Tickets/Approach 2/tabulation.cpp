#include <iostream>
#include <vector>
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, 1e9);
    dp[n] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        int call1 = costs[0] + dp[ind + 1];
        int i;
        for (i = ind; i < n && days[i] < days[ind] + 7; i++)
            ;
        int call2 = costs[1] + dp[i];
        for (i = ind; i < n && days[i] < days[ind] + 30; i++)
            ;
        int call3 = costs[2] + dp[i];

        dp[ind] = min(call1, min(call2, call3));
    }

    return dp[0];
}

int main()
{

    return 0;
}