#include<iostream>
#include <vector>
#include <limits>
#include <math.h>
using namespace std;

#define inf numeric_limits<int>::max()

int frogJump(int n, vector<int> &heights)
{
    int prev = 0, prev2 = 0;
    int curr;
    int fs = inf, ss = inf;
    for(int i=1; i<n; i++)
    {
        fs = prev + fabs(heights[i]-heights[i-1]);
                        
        if(i>1)
        ss = prev2 + fabs(heights[i] - heights[i-2]);
        
        curr = min(fs,ss);
        
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}

int main()
{
    
    return 0;
}