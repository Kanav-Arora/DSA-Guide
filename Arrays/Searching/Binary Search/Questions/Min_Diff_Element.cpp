/*
    Given a sorted array and a key

    Find the element from the sorted array such that the difference of key and given element is minimum
*/

#include<iostream>
using namespace std;

int MinimumDiff(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start<end)
    {
        mid = start + (end-start)/2;

        if(arr[mid]<=target)     start = mid;
        else    end = mid-1;
    }

    int lower = start;

    start = 0;
    end = n-1;
    mid = start + (end-start)/2;

    while(start<end)
    {
        mid = start + (end-start)/2;

        if(arr[mid]<target)     start = mid+1;
        else    end = mid;
    }
    int upper = start;

    if(abs(target-arr[lower]) < abs(target - arr[upper]))
        return lower;
    else
        return upper;
    
    return -1;
}

int main()
{
    int arr[] = {4,6,10,11};
    cout<<MinimumDiff(arr,4,7);
    return 0;
}