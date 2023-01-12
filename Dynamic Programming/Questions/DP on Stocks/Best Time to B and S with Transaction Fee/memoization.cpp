#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solver(vector<int> &p, int ind, bool av, vector<vector<int>> &dp, int fee)
    {
        if (ind == p.size())
            return 0;

        if (dp[ind][av] != -1)
            return dp[ind][av];

        int val = 0;
        if (av)
        {
            int notsell = solver(p, ind + 1, true, dp, fee);
            int sell = p[ind] - fee + solver(p, ind + 1, false, dp, fee);

            val = max(val, max(notsell, sell));
        }
        else
        {
            int notbuy = solver(p, ind + 1, false, dp, fee);
            int buy = -p[ind] + solver(p, ind + 1, true, dp, fee);

            val = max(val, max(notbuy, buy));
        }
        return dp[ind][av] = val;
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solver(prices, 0, false, dp, fee);
    }
};

int main()
{

    return 0;
}