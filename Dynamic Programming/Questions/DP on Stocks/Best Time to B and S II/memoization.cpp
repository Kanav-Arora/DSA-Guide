#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solver(vector<int> &p, int ind, bool av, vector<vector<int>> &dp)
    {
        if (ind == p.size())
            return 0;

        if (dp[ind][av] != -1)
            return dp[ind][av];

        int val = 0;
        if (av)
        {
            int notsell = solver(p, ind + 1, true, dp);
            int sell = p[ind] + solver(p, ind + 1, false, dp);

            val = max(val, max(notsell, sell));
        }
        else
        {
            int notbuy = solver(p, ind + 1, false, dp);
            int buy = -p[ind] + solver(p, ind + 1, true, dp);

            val = max(val, max(notbuy, buy));
        }
        return dp[ind][av] = val;
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solver(prices, 0, false, dp);
    }
};

int main()
{

    return 0;
}