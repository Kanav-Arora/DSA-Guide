#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &num, int tar, int ind)
{
    if (tar == 0)
        return 1;
    if (ind == 0)
        return tar == num[0] ? 1 : 0;

    int nottake = solve(num, tar, ind - 1);
    int take = 0;
    if (tar >= num[ind])
        take = solve(num, tar - num[ind], ind - 1);
    return take + nottake;
}

int findWays(vector<int> &num, int tar)
{
    return solve(num, tar, num.size() - 1);
}

int main()
{

    return 0;
}