#include <iostream>
#include <vector>
using namespace std;

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
    prev[0] = curr[0] = 1;
    if (num[0] <= tar)
        prev[num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int k = 0; k <= tar; k++)
        {
            int nottake = prev[k];
            int take = 0;
            if (k >= num[ind])
                take = prev[k - num[ind]];
            curr[k] = take + nottake;
        }
        prev = curr;
    }
    return prev[tar];
}

int main()
{

    return 0;
}