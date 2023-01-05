#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int> &arr, int index, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (index == 0)
        return arr[0] == k;
    if (dp[index][k] != -1)
        return dp[index][k];
    bool nottake = solve(arr, index - 1, k, dp);
    bool take = false;
    if (k >= arr[index])
        take = solve(arr, index - 1, k - arr[index], dp);
    return dp[index][k] = take || nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(1001, vector<int>(1001, -1));
    return solve(arr, arr.size() - 1, k, dp);
}

int main()
{

    return 0;
}