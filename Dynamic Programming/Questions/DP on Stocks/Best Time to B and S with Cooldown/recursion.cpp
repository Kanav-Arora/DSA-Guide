#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int solver(vector<int> &p, int ind, bool canbuy)
    {
        if (ind >= p.size())
            return 0;

        int val = 0;
        if (!canbuy)
        {
            int notsell = solver(p, ind + 1, false);
            int sell = p[ind] + solver(p, ind + 2, true);
            val = max(notsell, sell);
        }
        else
        {
            int notbuy = solver(p, ind + 1, true);
            int buy = -p[ind] + solver(p, ind + 1, false);

            val = max(notbuy, buy);
        }
        return val;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return solver(prices, 0, true);
    }
};

int main()
{

    return 0;
}