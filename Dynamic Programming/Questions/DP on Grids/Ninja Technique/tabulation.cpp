#include<iostream>
#include <vector>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,-1));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1],points[0][2]));

    for(int day=1; day<n; day++)
    {
        for(int last = 0; last<4; last++)
        {
            for(int task = 0; task<3; task++)
            {
                if(task!=last)
                {
                    int point = points[day][last] + dp[day-1][task];
                    // int val = dp[day][last];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }

    return dp[n-1][3];
}

int main()
{
    
    return 0;
}