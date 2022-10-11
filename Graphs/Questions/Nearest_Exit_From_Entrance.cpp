/*
    Leetcode question :- 1926.

    Basic queue solution will give TLE

    Analysis of TLE is here:

    https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/discuss/1329445/An-analysis-on-Time-Limit-Exceeded-(TLE)


*/

#include <iostream>
#include<queue>
using namespace std;

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    int ans = 0;

    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt-- > 0)
        {
            auto front = q.front();
            q.pop();

            int i = front.first;
            int j = front.second;

            if ((i == 0 || i == maze.size() - 1 || j == 0 || j == maze[0].size() - 1) && !(j == entrance[1] && i == entrance[0]))
                return ans;

            int drow[] = {0, -1, 0, 1};
            int dcol[] = {-1, 0, 1, 0};

            for (int k = 0; k < 4; k++)
            {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];

                if (nrow >= 0 && nrow < maze.size() && ncol >= 0 && ncol < maze[0].size() && maze[nrow][ncol] == '.')
                {
                    q.push({nrow, ncol});
                    maze[nrow][ncol] = '+';
                }
            }
        }
        ++ans;
    }

    return -1;
}

int main()
{

    return 0;
}