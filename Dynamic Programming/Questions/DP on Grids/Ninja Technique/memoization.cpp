#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &points, int day, int last, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int pts = points[day][i];
                maxi = max(maxi, pts);
            }
        }
        return maxi;
    }

    if (dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int pts = points[day][i] + solve(points, day - 1, i, dp);
            maxi = max(maxi, pts);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(points, n - 1, 3, dp);
}

int main()
{
    int n;
    cin >> n;
    cout << n;
    return 0;
}