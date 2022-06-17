#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include<numeric>
using namespace std;

int RainWaterTrapping(vector<int> v, int n)
{

    int mxh = INT_MIN;

    vector<int> res;
    for(int i=0; i<n; i++)
    {
        mxh = max(mxh, v[i]);
        res.push_back(mxh);
    }


    for(int i=n-1; i>-1; i--)
    {
        mxh = max(mxh, v[i]);
        res[i] = min(res[i],mxh);
    }

    for(int i=0; i<n; i++)
    {
        res[i] = res[i] - v[i];
    }

    return accumulate(res.begin(), res.end(), 0);
}

int main()
{
    vector<int> v = {3,0,0,2,0,4};

    cout<<RainWaterTrapping(v,6);
    return 0;
}