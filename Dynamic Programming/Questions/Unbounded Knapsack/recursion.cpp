#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int solve(vector<int> &profit, vector<int> &weight, int ind, int w)
{
    if (w == 0)
        return 0;
    if (ind == 0)
    {
        if (w >= weight[0])
            return (w / weight[0]) * profit[0];
        else
            return 0;
    }

    int nottake = solve(profit, weight, ind - 1, w);
    int take = INT_MIN;
    if (w >= weight[ind])
        take = profit[ind] + solve(profit, weight, ind, w - weight[ind]);

    return max(take, nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return solve(profit, weight, n - 1, w);
}

int main()
{

    return 0;
}