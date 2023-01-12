#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int av = 0; av <= 1; av++)
            {
                int val = 0;
                if (av)
                {
                    int notsell = dp[ind + 1][1];
                    int sell = prices[ind] - fee + dp[ind + 1][0];
                    val = max(notsell, sell);
                }
                else
                {
                    int notbuy = dp[ind + 1][0];
                    int buy = -prices[ind] + dp[ind + 1][1];

                    val = max(notbuy, buy);
                }
                dp[ind][av] = val;
            }
        }

        return dp[0][0];
    }
};

int main()
{

    return 0;
}