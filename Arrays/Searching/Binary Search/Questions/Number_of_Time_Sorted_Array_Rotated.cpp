/*
    Number of times a Sorted Array is Rotated
*/

#include<iostream>
using namespace std;


/*
    This problem can be solved by finding the index of peak element
*/

int NumberOfRotations(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;


    while(start<end)
    {
        if((mid==0 || arr[mid-1]<arr[mid]) && (mid==n-1 || arr[mid+1]<arr[mid]))
            return n-(mid+1);
        else if(arr[mid-1]>arr[mid])
            start = mid-1;
        else if(arr[mid+1]>arr[mid])
            end = mid+1;
    }

}

int main()
{
    int arr[] = {11,12,15,18,2,5,6,8};
    cout<<NumberOfRotations(arr,8);
    return 0;
}