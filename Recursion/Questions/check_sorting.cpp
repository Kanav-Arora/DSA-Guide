/*
    Check if an array is sorted or not
*/

#include<iostream>
using namespace std;

bool sort(int arr[], int n)
{
    if(n==1)
    {
        return true;
    }
    bool restArr = sort(arr+1, n-1);
    return arr[0]<arr[1] && restArr;
}

int main()
{
    int arr[] = {2,3,1,5,3};
    int n=5;
    cout<<sort(arr,n)<<endl;
    return 0;
}