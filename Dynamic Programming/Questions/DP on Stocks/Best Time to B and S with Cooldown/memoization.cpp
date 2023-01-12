#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int solver(vector<int> &p, int ind, bool canbuy, vector<vector<int>> dp)
    {
        if (ind >= p.size())
            return 0;

        if (dp[ind][canbuy] != -1)
            return dp[ind][canbuy];

        int val = 0;
        if (!canbuy)
        {
            int notsell = solver(p, ind + 1, false, dp);
            int sell = p[ind] + solver(p, ind + 2, true, dp);
            val = max(notsell, sell);
        }
        else
        {
            int notbuy = solver(p, ind + 1, true, dp);
            int buy = -p[ind] + solver(p, ind + 1, false, dp);

            val = max(notbuy, buy);
        }
        return dp[ind][canbuy] = val;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solver(prices, 0, true, dp);
    }
};

int main()
{

    return 0;
}