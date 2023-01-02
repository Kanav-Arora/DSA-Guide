#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> vec(maxWeight+1,0);
    for (int i = weight[0]; i <= maxWeight; i++)
        vec[i] = value[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = maxWeight; wt>=0; wt--)
        {
            int notpick = vec[wt];
            int pick = INT_MIN;
            if (wt >= weight[ind])
                pick = value[ind] + vec[wt - weight[ind]];
            vec[wt] = max(pick, notpick);
        }
    }

    return vec[maxWeight];
}

int main()
{

    return 0;
}