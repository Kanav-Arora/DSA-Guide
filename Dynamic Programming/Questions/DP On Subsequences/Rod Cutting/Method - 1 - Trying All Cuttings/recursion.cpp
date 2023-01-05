#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int solve(vector<int> &price, int len)
{
    if (len == 0)
        return 0;
    int maxi = INT_MIN;
    for (int i = 1; i <= price.size(); i++)
    {
        if (i <= len)
        {
            int call = solve(price, len - i) + price[i - 1];
            maxi = maxi > call ? maxi : call;
        }
    }

    return maxi;
}

int cutRod(vector<int> &price, int n)
{
    return solve(price, n);
}

int main()
{

    return 0;
}