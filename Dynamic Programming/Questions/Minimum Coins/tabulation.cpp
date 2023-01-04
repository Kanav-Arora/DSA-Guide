#include <iostream>
#include <vector>
using namespace std;

int minimumElements(vector<int> &num, int x)
{
    vector<vector<int>> dp(num.size(), vector<int>(x + 1, 0));

    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            dp[0][i] = i / num[0];
        else
            dp[0][i] = 1e9;
    }

    for (int ind = 1; ind < num.size(); ind++)
    {
        for (int t = 0; t <= x; t++)
        {
            int nottake = dp[ind - 1][t];
            int take = 1e9;
            if (num[ind] <= t)
                take = 1 + dp[ind][t - num[ind]];
            dp[ind][t] = min(nottake, take);
        }
    }
    int val = dp[num.size() - 1][x];
    return val >= 1e9 ? -1 : val;
}

int main()
{

    return 0;
}