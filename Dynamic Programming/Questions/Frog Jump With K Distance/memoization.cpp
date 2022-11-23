#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <cstring>
using namespace std;

int dp[100001];

int solve(vector<int> &heights, int i, int k)
{
    if (i == 0)
        return 0;

    int mini = numeric_limits<int>::max();

    for (int m = 1; m <= k; m++)
    {
        if (i - m < 0)
            break;

        int val;
        if (dp[i - m] != -1)
            val = dp[i - m] + fabs(heights[i] - heights[i - m]);
        else
            val = solve(heights, i - m, k) + fabs(heights[i] - heights[i - m]);

        mini = min(mini, val);
    }

    dp[i] = mini;

    return mini;
}

int jump(int n, vector<int> &heights, int k)
{
    memset(dp, -1, sizeof(dp));
    return solve(heights, n - 1, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> inp;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        inp.push_back(val);
    }

    cout << jump(n, inp, k) << endl;

    return 0;
}