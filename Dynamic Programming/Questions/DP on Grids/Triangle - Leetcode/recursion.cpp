#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &triangle, int i, int j)
{
    if (i == triangle.size() - 1)
        return triangle[triangle.size() - 1][j];

    int curr = triangle[i][j];
    int down = curr + solve(triangle, i + 1, j);
    int diag = curr + solve(triangle, i + 1, j + 1);
    return min(down, diag);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    return solve(triangle, 0, 0);
}

int main()
{

    return 0;
}