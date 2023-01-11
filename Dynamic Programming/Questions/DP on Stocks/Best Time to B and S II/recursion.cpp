#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solver(vector<int> &p, int ind, bool av)
    {
        if (ind == p.size())
            return 0;

        int val = 0;
        if (av)
        {
            int notsell = solver(p, ind + 1, true);
            int sell = p[ind] + solver(p, ind + 1, false);

            val = max(val, max(notsell, sell));
        }
        else
        {
            int notbuy = solver(p, ind + 1, false);
            int buy = -p[ind] + solver(p, ind + 1, true);

            val = max(val, max(notbuy, buy));
        }
        return val;
    }

    int maxProfit(vector<int> &prices)
    {
        return solver(prices, 0, false);
    }
};

int main()
{

    return 0;
}