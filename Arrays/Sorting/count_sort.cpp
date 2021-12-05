#include<iostream>
#include <climits>
using namespace std;

void countSort(int arr[], int n)
{
    int maxi = INT_MIN;
    for(int i=0; i<n; i++)
    {
        maxi = max(maxi,arr[i]);
    }
    int count[maxi+1];
    for(int i=0; i<=maxi; i++)
    {
        count[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }

    for(int i=1; i<=maxi; i++)
    {
        count[i]+= count[i-1];
    }
    int ptr = n-1;
    int soln[n];
    while(ptr>=0)
    {
        soln[--count[arr[ptr]]] = arr[ptr];
        ptr--;
    }
    for(int i=0; i<n; i++)
    {
        arr[i] = soln[i];
        // arr[n-i-1] = soln[i];    for decreasing order
    }
}

int main()
{
    int arr[] = {1,3,2,3,4,1,6,4,3};
    int n = 9;
    int sol[n];
    countSort(arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}