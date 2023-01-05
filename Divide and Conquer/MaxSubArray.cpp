#include <iostream>
#include <vector>
using namespace std;

#define neg_inf -1e9
#define inf 1e9

int maxElement(vector<int> &prices, int l, int u)
{
    int maxi = neg_inf;
    for (int i = l; i <= u; i++)
        maxi = maxi>prices[i] ? maxi : prices[i];
    return maxi;
}

int minElement(vector<int> &prices, int l, int u)
{
    int mini = inf;
    for (int i = l; i <= u; i++)
    {
        mini = mini>prices[i] ? prices[i] : mini;
    }
    return mini;
}

int maxSubArray(vector<int> prices, int l, int u)
{
    if (u == l)
        return 0;
    else if (u == l + 1)
        return prices[u] - prices[l]>0 ? prices[u] - prices[l] : 0;
    int m = (u + l) / 2;
    int m1 = maxSubArray(prices, l, m);
    int m2 = maxSubArray(prices, m + 1, u);
    int y = maxElement(prices, m + 1, u);
    int x = minElement(prices, l, m);
    return max(max(m1, m2), y - x);
}

int maxProfit(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;
    return maxSubArray(prices, 0, prices.size() - 1);
}

int main()
{
    int n;
    vector<int> prices;
    for(int i = 0; i<n; i++)
    {
        int val;
        cin>>val;
        prices.push_back(val);
    }
    cout<<maxProfit(prices);
    return 0;
}