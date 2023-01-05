#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int> &arr, int index, int k)
{
    if (k == 0)
        return true;
    if (index == 0)
        return arr[0] == k;

    bool nottake = solve(arr, index - 1, k);
    bool take = false;
    if (k >= arr[index])
        take = solve(arr, index - 1, k - arr[index]);
    return take || nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return solve(arr, arr.size() - 1, k);
}

int main()
{

    return 0;
}