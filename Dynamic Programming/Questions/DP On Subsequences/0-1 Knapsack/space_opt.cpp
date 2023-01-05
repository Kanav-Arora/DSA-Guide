#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight+1,0), curr(maxWeight+1,0); 
    for (int i = weight[0]; i <= maxWeight; i++)
        prev[i] = value[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int notpick = prev[wt];
            int pick = INT_MIN;
            if (wt >= weight[ind])
                pick = value[ind] + prev[wt - weight[ind]];
            curr[wt] = max(pick, notpick);
        }
        prev = curr;
    }

    return prev[maxWeight];
}

int main()
{

    return 0;
}