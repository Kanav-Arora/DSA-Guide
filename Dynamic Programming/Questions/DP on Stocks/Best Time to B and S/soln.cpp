#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> arr)
{
    int mini = arr[0], profit = 0;

    for(int i=1; i<arr.size(); i++)
    {
        profit = profit>arr[i]-mini ? profit : arr[i]-mini;
        mini = mini<arr[i] ? mini : arr[i];
    }

    return profit;
}

// buy and sell once

int main()
{
    int n;
    cin>>n;
    vector<int> inp;

    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        inp.push_back(val);
    }

    cout<<solve(inp)<<endl;

    return 0;
}