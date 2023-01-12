#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solver(vector<int> &p, int ind, bool av, int fee)
    {
        if (ind == p.size())
            return 0;

        int val = 0;
        if (av)
        {
            int notsell = solver(p, ind + 1, true, fee);
            int sell = p[ind] - fee + solver(p, ind + 1, false, fee);

            val = max(notsell, sell);
        }
        else
        {
            int notbuy = solver(p, ind + 1, false, fee);
            int buy = -p[ind] + solver(p, ind + 1, true, fee);

            val = max(notbuy, buy);
        }
        return val;
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        return solver(prices, 0, false, fee);
    }
};

int main()
{

    return 0;
}