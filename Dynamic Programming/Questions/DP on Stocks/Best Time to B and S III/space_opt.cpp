#include <iostream>
#include <vector>
using namespace std;

// (2 x 3) x 2 vector solution is not that much intuitive

// This solution has a space complexity of (3 x 4) vector

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int transact = 0;
        int n = prices.size();
        vector<int> aheadCan(3, 0), aheadCannot(3, 0), currCan(3, 0), currCannot(3, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int transact = 0; transact <= 1; transact++)
                {
                    if (!canBuy)
                    {
                        int notsell = aheadCannot[transact];
                        int sell = prices[ind] + aheadCan[transact + 1];

                        currCannot[transact] = max(notsell, sell);
                    }
                    else
                    {
                        int notbuy = aheadCan[transact];
                        int buy = -prices[ind] + aheadCannot[transact];

                        currCan[transact] = max(notbuy, buy);
                    }
                }
            }
            aheadCan = currCan;
            aheadCannot = currCannot;
        }
        return aheadCan[0];
    }
};

int main()
{

    return 0;
}