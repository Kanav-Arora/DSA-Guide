#include<iostream>
using namespace std;

long solver(long* v,int n,int index, bool buy)
{
    if(index==n)
    {
        return 0;
    }
    long profit = 0;
    if(buy)
    {
        long take = -v[index] + solver(v,n,index+1,0);
        long nottake = 0 + solver(v,n,index+1,1);
        
        profit =  max(take,nottake);
    }
    else
    {
        long sell = v[index] + solver(v,n,index+1,1);
        long notsell = 0 + solver(v,n,index+1,0);
        
        profit = max(sell,notsell);
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{   
    return solver(values,n,0,1);
}

int main()
{
    
    return 0;
}