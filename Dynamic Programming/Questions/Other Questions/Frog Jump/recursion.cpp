#include<iostream>
#include <vector>
#include <math.h>
using namespace std;

int solve(vector<int> &heights, int i)
{
    if(i==0)    return 0;
    if(i==1)    return fabs(heights[1]-heights[0]);
    
    int left = solve(heights,i-1) + fabs(heights[i]-heights[i-1]);
    int right = solve(heights,i-2) + fabs(heights[i] - heights[i-2]);
    
    return min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    return solve(heights, n-1);
}

int main()
{
    
    return 0;
}