#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> curr(2, 0), ahead(2, 0), ahead2(2, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            int notsell = ahead[0];
            int sell = prices[ind] + ahead2[1];
            curr[0] = max(notsell, sell);

            int notbuy = ahead[1];
            int buy = -prices[ind] + ahead[0];

            curr[1] = max(notbuy, buy);

            ahead2 = ahead;
            ahead = curr;
        }

        return ahead[1];
    }
};

int main()
{

    return 0;
}