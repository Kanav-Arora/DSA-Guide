#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solver(vector<int> p, int ind, bool canBuy, int transact)
    {
        if (transact == 2 || ind == p.size())
            return 0;

        int val = 0;
        if (!canBuy)
        {
            int notsell = solver(p, ind + 1, false, transact);
            int sell = p[ind] + solver(p, ind + 1, true, transact + 1);

            val = max(notsell, sell);
        }
        else
        {
            int notbuy = solver(p, ind + 1, true, transact);
            int buy = -p[ind] + solver(p, ind + 1, false, transact);

            val = max(notbuy, buy);
        }
        return val;
    }

    int maxProfit(vector<int> &prices)
    {
        int transact = 0;
        return solver(prices, 0, true, transact);
    }
};

int main()
{

    return 0;
}