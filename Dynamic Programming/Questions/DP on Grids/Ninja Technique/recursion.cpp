#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &points, int day, int last)
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

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int pts = points[day][i] + solve(points, day - 1, i);
            maxi = max(maxi, pts);
        }
    }

    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solve(points, n - 1, 3);
}

int main()
{
    int n;
    cin >> n;
    cout << n;
    return 0;
}