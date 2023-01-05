#include <iostream>
#include <vector>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0), curr(w + 1, 0);
    for (int i = 0; i <= w; i++)
        prev[i] = i >= weight[0] ? (i / weight[0]) * profit[0] : 0;

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int nottake = prev[wt];
            int take = -1e9;
            if (wt >= weight[ind])
                take = profit[ind] + curr[wt - weight[ind]];

            curr[wt] = max(take, nottake);
        }
        prev = curr;
    }

    return prev[w];
}

int main()
{

    return 0;
}