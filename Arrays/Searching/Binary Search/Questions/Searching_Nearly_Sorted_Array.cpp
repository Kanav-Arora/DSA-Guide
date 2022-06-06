/*
        Nearly Sorted Array is array in which ith element is on (i-1)th, ith, (i+1)th index
*/

#include<iostream>
using namespace std;

int NearlySorted(int arr[], int n, int target)
{
    int low =0;
    int high = n-1;
    int mid = low + (high-low)/2;

    while(low<high)
    {
        mid = low + (high-low)/2;

        if(arr[mid]==target)
            return mid;
        
        else if(arr[mid-1]==target)
            return mid-1;
        
        else if(arr[mid+1]==target)
            return mid+1;

        else if(target>arr[mid] || target>arr[mid-1] || target>arr[mid+1])
            low = mid+2;
        
        else
            high = mid-2;
    }

    return -1;
}

int main()
{
    int arr[] = {5,10,30,20,40, 50, 80, 70, 90};
    cout<<NearlySorted(arr,9,70);
    return 0;
}