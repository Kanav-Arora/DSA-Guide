#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int abs(int a, int b)
    {
        int sub = a - b;
        return sub < 0 ? sub * -1 : sub;
    }

    long long solver(vector<vector<int>> &points, int r, int c, int i, int j, int prev, vector<vector<vector<long long>>> &dp)
    {
        if (i == r || j == c)
            return 0;

        if (dp[i][j][prev + 1] != -1)
            return dp[i][j][prev + 1];

        long long pick = points[i][j] + solver(points, r, c, i + 1, 0, j, dp);
        if (prev != -1)
            pick -= abs(j, prev);

        long long dont = solver(points, r, c, i, j + 1, prev, dp);

        return dp[i][j][prev + 1] = max(pick, dont);
    }

public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int rows = points.size();
        int cols = points[0].size();
        vector<vector<vector<long long>>> dp(rows, vector<vector<long long>>(cols, vector<long long>(cols + 1, -1)));
        long long ans = solver(points, rows, cols, 0, 0, -1, dp);
        return ans;
    }
};

int main()
{

    return 0;
}