#include <iostream>
#include <vector>
using namespace std;

int solve(vector< vector< int> > &mat, int m, int n, int i, int j, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if(mat[i][j]==-1)   return 0;

    return dp[i][j] = solve(mat,m, n, i + 1, j,dp) + solve(mat,m, n, i, j + 1,dp);
}

int uniquePaths(int m, int n, vector< vector< int> > &mat)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(mat,m, n, 0, 0,dp);
}

int main()
{

    return 0;
}

// T.C : O(m*n)
// S.C : O(n-1 + m-1) + O(m*n)