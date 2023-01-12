#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int av = 0; av <= 1; av++)
            {
                int val = 0;
                if (av)
                {
                    int notsell = ahead[1];
                    int sell = prices[ind] - fee + ahead[0];

                    val = max(notsell, sell);
                }
                else
                {
                    int notbuy = ahead[0];
                    int buy = -prices[ind] + ahead[1];

                    val = max(notbuy, buy);
                }
                curr[av] = val;
            }
            ahead = curr;
        }

        return ahead[0];
    }
};

int main()
{

    return 0;
}