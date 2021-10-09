/*
        Given an array a[] of size n. For every i from 0 to n-1. Output max(a[0],a[1]...)
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxOfArray(const int* arr, int n)
{
    int max = *arr;
    for(int i =0; i<n; i++)
    {
        if(*(arr+i)>max)
        {
            max = *(arr+i);
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    int max = maxOfArray(arr, n);
    cout<<"Max of array: "<<max<<endl;
    return 0;
}