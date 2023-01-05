#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <cstring>
using namespace std;

int dp[100001];

int jump(int n, vector<int> &heights, int k)
{
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;

    for(int i=1; i<n; i++)
    {
        int mini = numeric_limits<int>::max();

        for(int j=1; j<=k; j++)
        {
            if(i-j>=0)
            {
                int jump = dp[i-j] + fabs(heights[i]-heights[i-j]);
                mini = min(mini,jump);
            }
        }

        dp[i] = mini;
    }

    return dp[n-1];
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