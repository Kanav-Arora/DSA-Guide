#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int ans = 0;
    queue<pair<int, int>> weekly;  // day, cost till that day
    queue<pair<int, int>> monthly; // day, cost till that day

    for (int day : days)
    {
        while (!monthly.empty() && monthly.front().first + 30 <= day)
        {
            monthly.pop();
        }
        while (!weekly.empty() && weekly.front().first + 7 <= day)
        {
            weekly.pop();
        }
        weekly.push({day, costs[1]});
        monthly.push({day, costs[2]});

        ans = min(ans + costs[0], min(weekly.front().second, monthly.front().second));
    }
    return ans;
}

int main()
{

    return 0;
}