#include <iostream>
#include <vector>
using namespace std;

int solver(vector<int> p, int k, int ind, bool canBuy, int transact)
{
    if (transact == k || ind == p.size())
        return 0;

    int val = 0;
    if (!canBuy)
    {
        int notsell = solver(p, k, ind + 1, false, transact);
        int sell = p[ind] + solver(p, k, ind + 1, true, transact + 1);

        val = max(notsell, sell);
    }
    else
    {
        int notbuy = solver(p, k, ind + 1, true, transact);
        int buy = -p[ind] + solver(p, k, ind + 1, false, transact);

        val = max(notbuy, buy);
    }
    return val;
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    int transact = 0;
    return solver(prices, k, 0, true, transact);
}

int main()
{

    return 0;
}