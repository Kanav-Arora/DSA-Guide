#include<iostream>
using namespace std;

int fib(int n)
{
    int memo[n+1];  // memoization
    memo[0] = 1;
    memo[1] = 1;

    for(int i=2; i<=n; i++)
    {
        memo[i] = memo[i-1] + memo[i-2];
    }

    return memo[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}