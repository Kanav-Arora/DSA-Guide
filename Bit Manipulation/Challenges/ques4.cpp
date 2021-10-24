/*
        Given an array of size n. All elements occur two types except one find that unique element.
*/

#include<iostream>
using namespace std;

int unique(int arr[], int n)
{
    int xorsum=0;
    for(int i=0; i<n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }

    return xorsum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<unique(arr,n)<<endl;
    return 0;
}