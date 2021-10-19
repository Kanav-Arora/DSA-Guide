/*

Companies: Amazon, Oracle

                    First Repeating Element

    Given an array of size N. Find the first repeating element in the array of integers.


    Input:

    7
    1 5 3 4 3 5 6

    Output:
    1

*/

#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        int num;
        cin>>num;
        arr[i] = num;
    }
    
    const int N = 1e6;
    int idx[N];
    for(int i=0; i<N; i++)
    {
        idx[i] = -1;
    }

    int minidx = INT_MAX;

    for(int i=0; i<n; i++)
    {
        int val = arr[i];
        if(idx[val]==-1)
        {
            idx[val] = i;
        }
        else{
            if(idx[val]<minidx)
                minidx = idx[val];
        }
    }

    if(minidx==INT_MAX)
    minidx = -1;

    cout<<minidx<<endl;
    return 0;
}