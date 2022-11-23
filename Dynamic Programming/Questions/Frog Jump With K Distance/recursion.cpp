#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
using namespace std;

int solve(vector<int> &heights, int i, int k)
{
    if (i == 0)
        return 0;

    int mini = numeric_limits<int>::max();

    for (int m = 1; m <= k; m++)
    {
        if (i - m < 0)
            break;
        int val = solve(heights, i - m, k) + fabs(heights[i] - heights[i - m]);
        mini = min(mini, val);
    }
    return mini;
}

int jump(int n, vector<int> &heights, int k)
{
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