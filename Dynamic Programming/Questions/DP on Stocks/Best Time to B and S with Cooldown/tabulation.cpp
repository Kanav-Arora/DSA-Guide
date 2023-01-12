#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int canbuy = 0; canbuy <= 1; canbuy++)
            {
                int val = 0;
                if (!canbuy)
                {
                    int notsell = dp[ind + 1][0];
                    int sell = prices[ind] + dp[ind + 2][1];
                    val = max(notsell, sell);
                }
                else
                {
                    int notbuy = dp[ind + 1][1];
                    int buy = -prices[ind] + dp[ind + 1][0];

                    val = max(notbuy, buy);
                }
                dp[ind][canbuy] = val;
            }
        }

        return dp[0][1];
    }
};

int main()
{

    return 0;
}