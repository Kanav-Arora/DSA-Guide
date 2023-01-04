#include <iostream>
#include <vector>
using namespace std;

int minimumElements(vector<int> &num, int x)
{
    vector<int> prev(x + 1, 0), curr(x + 1, 0);

    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            prev[i] = i / num[0];
        else
            prev[i] = 1e9;
    }

    for (int ind = 1; ind < num.size(); ind++)
    {
        for (int t = 0; t <= x; t++)
        {
            int nottake = prev[t];
            int take = 1e9;
            if (num[ind] <= t)
                take = 1 + curr[t - num[ind]];
            curr[t] = min(nottake, take);
        }
        prev = curr;
    }
    int val = prev[x];
    return val >= 1e9 ? -1 : val;
}

int main()
{

    return 0;
}