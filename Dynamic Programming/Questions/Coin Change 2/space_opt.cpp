#include <iostream>
#include <vector>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value + 1, 0), curr(value + 1, 0);
    for (int i = 0; i < n; i++)
        prev[0] = 1;
    for (int i = 0; i <= value; i++)
    {
        if (i % denominations[0] == 0)
            prev[i] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int val = 0; val <= value; val++)
        {
            long notpick = prev[val];
            long pick = 0;
            if (denominations[ind] <= val)
                pick = curr[val - denominations[ind]];
            curr[val] = notpick + pick;
        }
        prev = curr;
    }

    return curr[value];
}

int main()
{

    return 0;
}