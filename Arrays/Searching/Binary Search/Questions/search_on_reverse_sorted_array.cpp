/*
    Search for element in a reverse sorted array.
*/


#include<iostream>
using namespace std;

int ReverseSortedSearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start<end)
    {
        mid = start + (end-start)/2;

        if(arr[mid]==target)
            return mid;
        else if(arr[mid]<target)
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}


int main()
{
    int arr[] = {20,14,12,11,9,4,2,1};
    cout<<ReverseSortedSearch(arr,8,4);
    return 0;
}