/*
    Print numbers till n in increasing and decreasing order
*/

#include<iostream>
using namespace std;

void decArr(int* arr, int n)
{
    if(n==0)
    {
        return;
    }
    *arr = n;
    arr++;
    decArr(arr,n-1);
}

void incArr(int* arr, int n)
{
    if(n==0)
    {
        cout<<endl;
        return;
    }
    arr--;
    incArr(arr,n-1);
    *arr = n;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    incArr(arr+n,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}