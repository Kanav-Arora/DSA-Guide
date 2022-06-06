#include<iostream>
using namespace std;

int lower_bound(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid = 0;
    while(start<end)
    {
        mid = start  + (end-start)/2;
        if(arr[mid]<target)    start = mid+1;
        else   end = mid;
    }
    return start;
}

int upper_bound(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid = 0;
    while(start<end)
    {
        mid = start  + (end-start)/2;
        if(arr[mid]<=target)    start = mid+1;
        else   end = mid;
    }
    return start;
}

int CountElement(int arr[], int n, int target)
{
    int low = lower_bound(arr,n, target);

    if(low==n-1 || arr[low]!=target)
        return 0;

    int high = upper_bound(arr,n,target);

    return high-low;

}

int main()
{
    int arr[] = {1,4,5,6,10,10,10,12,14};
    cout<<CountElement(arr,9,10);
    return 0;
}