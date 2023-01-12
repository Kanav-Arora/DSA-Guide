#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k)
{
    int transact = 0;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int transact = 0; transact < k; transact++)
            {
                int val = 0;
                if (!canBuy)
                {
                    int notsell = dp[ind + 1][0][transact];
                    int sell = prices[ind] + dp[ind + 1][1][transact + 1];

                    val = max(notsell, sell);
                }
                else
                {
                    int notbuy = dp[ind + 1][1][transact];
                    int buy = -prices[ind] + dp[ind + 1][0][transact];

                    val = max(notbuy, buy);
                }
                dp[ind][canBuy][transact] = val;
            }
        }
    }
    return dp[0][1][0];
}

int main()
{

    return 0;
}