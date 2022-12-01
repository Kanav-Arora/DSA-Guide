#include <iostream>
#include<vector>
using namespace std;

int solve(vector< vector< int> > &mat, int m, int n, int i, int j)
{
    if (i >= m || j >= n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;

    if(mat[i][j]==-1)   return 0;

    return solve(mat,m, n, i + 1, j) + solve(mat,m, n, i, j + 1);
}

int uniquePaths(int m, int n, vector< vector< int> > &mat)
{
    return solve(mat,m, n, 0, 0);
}

int main()
{

    return 0;
}


// T.C : O(2^(m*n))
// S.C : O(path length) = O(m-1 + n-1)