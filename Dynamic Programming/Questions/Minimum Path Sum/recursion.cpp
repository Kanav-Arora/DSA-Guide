#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int solve(vector<vector<int>> &grid, int i, int j)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return numeric_limits<int>::max();

    return grid[i][j] + min(solve(grid, i, j - 1), solve(grid, i - 1, j));
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    return solve(grid, n - 1, m - 1);
}

int main()
{

    return 0;
}