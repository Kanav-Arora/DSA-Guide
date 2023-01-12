#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        int aheadBuy = 0, aheadNotbuy = 0, currBuy = 0, currNotbuy = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int notsell = aheadNotbuy;
            int sell = prices[ind] - fee + aheadBuy;

            currNotbuy = max(notsell, sell);

            int notbuy = aheadBuy;
            int buy = -prices[ind] + aheadNotbuy;

            currBuy = max(notbuy, buy);

            aheadNotbuy = currNotbuy;
            aheadBuy = currBuy;
        }

        return aheadBuy;
    }
};

int main()
{

    return 0;
}