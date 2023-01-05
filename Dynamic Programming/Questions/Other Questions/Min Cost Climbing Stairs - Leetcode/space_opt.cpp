#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int> cost)
{
    int n = cost.size();
    int first = cost[0];
    int second = cost[1];
    if (n <= 2)
        return min(first, second);
    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(first, second);
        first = second;
        second = curr;
    }
    return min(first, second);
}

int main()
{

    return 0;
}