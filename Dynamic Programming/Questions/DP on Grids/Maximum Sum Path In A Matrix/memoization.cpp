#include <iostream>
#include <vector>
#include <limits>
#define mini numeric_limits<int>::min()

using namespace std;

int solve(vector<vector<int>> &matrix, int n, int m, int i, int j)
{
    if (i == n - 1)
        return matrix[i][j];

    int down, left, right;
    down = left = right = matrix[i][j];

    if (i < n - 1)
        down += solve(matrix, n, m, i + 1, j);
    else
        down = mini;
    if (j > 0 && i < n - 1)
        left += solve(matrix, n, m, i + 1, j - 1);
    else
        left = mini;
    if (j < m - 1 && i < n - 1)
        right += solve(matrix, n, m, i + 1, j + 1);
    else
        right = mini;

    return max(down, max(left, right));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans(m, -1);

    for (int j = 0; j < m; j++)
    {
        ans[j] = solve(matrix, n, m, 0, j);
    }

    int maxi = mini;
    for (int j = 0; j < m; j++)
    {
        int curr = ans[j];
        maxi = max(maxi, curr);
    }

    return maxi;
}

int main()
{

    return 0;
}