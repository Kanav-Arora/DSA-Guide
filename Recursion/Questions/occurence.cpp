/*
    Find first and last occurence of an element in an array
*/

#include<iostream>
using namespace std;

int firstOcc(int arr[],int n, int ele, int i=0)
{
    if(i==n)
    {
        return -1;
    }
    if(arr[i]==ele)
        return i;
    
    return firstOcc(arr,n,ele, i+1);
}

int lastOcc(int arr[],int n,int ele,  int i=0)
{
    if(i==n)
        return -1;
    
    if(arr[n-i-1]==ele)
        return n-i-1;

    return lastOcc(arr, n,ele, i+1);
}

int main()
{
    int arr[] = {1,2,5,6,2,4};
    cout<<firstOcc(arr,6,2, 0)<<endl;
    cout<<lastOcc(arr,6,4,0)<<endl;
    return 0;
}