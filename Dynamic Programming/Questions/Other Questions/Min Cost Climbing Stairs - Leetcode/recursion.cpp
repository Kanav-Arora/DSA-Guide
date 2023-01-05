#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &cost, int n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return cost[n];
    return cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    return min(solve(cost, n - 1), solve(cost, n - 2));
}

int main()
{

    return 0;
}