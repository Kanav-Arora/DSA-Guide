#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -1e9

int solve(vector<int> &price, int ind, int len)
{
    if(ind==0)  return len*price[0];

    int nottake = 0 + solve(price,ind-1,len);
    int take = INT_MIN;
    int rest = ind+1;

    if(rest<=len)
        take = price[ind] + solve(price,ind,len-rest);

    return max(take,nottake);
}

int cutRod(vector<int> &price, int n)
{
    return solve(price, n-1, n);
}

int main()
{

    return 0;
}