#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &num, int ind, int x)
{
    if (ind == 0)
    {
        if (x % num[0] == 0)
        {
            return x / num[0];
        }
        else
            return 1e9;
    }

    int nottake = solve(num, ind - 1, x);
    int take = 1e9;
    if (num[ind] <= x)
        take = 1 + solve(num, ind, x - num[ind]);
    return min(nottake, take);
}

int minimumElements(vector<int> &num, int x)
{
    int val = solve(num, num.size() - 1, x);
    return val == 1e9 ? -1 : val;
}

// Infinite supply of coins

int main()
{

    return 0;
}