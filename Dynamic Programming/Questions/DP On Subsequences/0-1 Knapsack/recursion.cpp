#include <iostream>
#include <vector>
using namespace std;

int solver(vector<int> weight, vector<int> value, int ind, int wt)
{
    if (wt == 0)
        return 0;
    if (ind == 0)
        return wt >= weight[0] ? value[0] : 0;
    int notpick = solver(weight, value, ind - 1, wt);
    int pick = 0;
    if (wt >= weight[ind])
        pick = value[ind] + solver(weight, value, ind - 1, wt - weight[ind]);

    return max(pick, notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
}

int main()
{

    return 0;
}