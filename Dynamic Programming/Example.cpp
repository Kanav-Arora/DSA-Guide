#include<iostream>
using namespace std;

int callcounter = 0, dpcounter = 0;
int dp[50];

int helper(int n)
{
    callcounter++;
    if(n==1 || n==0)
        return 1;
    
    return helper(n-1) + helper(n-2);
}

int dphelper(int n)
{
    dpcounter++;

    if(n==1 || n==0)
        return 1;
    
    return dp[n]!=-1 ? dp[n] : dp[n] = dphelper(n-1) + dphelper(n-2);
}

int main()
{
    cout<<helper(10)<<"   "<<callcounter<<endl;

    for(int i=0; i<50; i++)
        dp[i] = -1;

    cout<<dphelper(10)<<"   "<<dpcounter<<endl;
    return 0;
}