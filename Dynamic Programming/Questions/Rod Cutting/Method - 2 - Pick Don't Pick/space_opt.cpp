#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1,0), curr(n+1,0);
    for(int N = 0; N<=n; N++)
    {
        prev[N] = N*price[0];
    }

    for(int ind = 1; ind<n; ind++)
    {
        for(int N = 0; N<=n; N++)
        {
            int nottake = prev[N];
            int take = INT_MIN;
            int rest = ind+1;

            if(rest<=N)
                take = price[ind] + curr[N-rest];
            curr[N] = max(take,nottake);
        }
        prev = curr;
    }

    return prev[n];
}

int main()
{

    return 0;
}