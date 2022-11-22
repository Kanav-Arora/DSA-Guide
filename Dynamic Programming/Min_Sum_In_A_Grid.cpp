#include<iostream>
#include<limits>
using namespace std;

#define n 10
#define m 10

int grid[n][m];
int dp[n][m];


int f(int i, int j)
{
    if(i>=n || j>=m)
        return numeric_limits<int>::max();

    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j] = grid[i][j] + min(f(i,j+1),f(i+1,j));
    return dp[i][j];
}

int main()
{
    
    return 0;
}