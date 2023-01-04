#include <iostream>
using namespace std;

long solve(int *den, int ind, int val)
{
    if (val == 0)
        return 1;
    if (ind == 0)
    {
        if (val % den[0] == 0)
            return 1;
        else
            return 0;
    }

    long notpick = solve(den, ind - 1, val);
    long pick = 0;
    if (den[ind] <= val)
        pick = solve(den, ind, val - den[ind]);
    return notpick + pick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return solve(denominations, n - 1, value);
}

int main()
{

    return 0;
}