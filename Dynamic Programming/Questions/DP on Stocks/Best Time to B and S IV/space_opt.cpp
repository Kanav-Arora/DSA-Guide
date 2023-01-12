#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k)
{
    int transact = 0;
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int transact = 2 * k - 1; transact >= 0; transact--)
        {
            bool canBuy = false;
            if (transact % 2 == 0)
                canBuy = true;
            int val = 0;
            if (!canBuy)
            {
                int notsell = dp[ind + 1][transact];
                int sell = prices[ind] + dp[ind + 1][transact + 1];

                val = max(notsell, sell);
            }
            else
            {
                int notbuy = dp[ind + 1][transact];
                int buy = -prices[ind] + dp[ind + 1][transact + 1];

                val = max(notbuy, buy);
            }
            dp[ind][transact] = val;
        }
    }
    return dp[0][0];
}

int main()
{

    return 0;
}