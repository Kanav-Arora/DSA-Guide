#include <iostream>
#include <vector>
using namespace std;

// Memoization technique code might give TLE on some platforms for larger test cases

class Solution
{
public:
    int solver(vector<int> p, int ind, bool canBuy, int transact, vector<vector<vector<int>>> &dp)
    {
        if (transact == 2 || ind == p.size())
            return 0;
        if (dp[ind][canBuy][transact] != -1)
            return dp[ind][canBuy][transact];
        int val = 0;
        if (!canBuy)
        {
            int notsell = solver(p, ind + 1, false, transact, dp);
            int sell = p[ind] + solver(p, ind + 1, true, transact + 1, dp);

            val = max(notsell, sell);
        }
        else
        {
            int notbuy = solver(p, ind + 1, true, transact, dp);
            int buy = -p[ind] + solver(p, ind + 1, false, transact, dp);

            val = max(notbuy, buy);
        }
        return dp[ind][canBuy][transact] = val;
    }

    int maxProfit(vector<int> &prices)
    {
        int transact = 0;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return solver(prices, 0, true, transact, dp);
    }
};

int main()
{

    return 0;
}