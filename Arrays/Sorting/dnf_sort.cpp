/*
                Dutch National Flag (DNF)
                    0,1,2 sort
*/

#include<iostream>
using namespace std;

void dnfSort(int arr[], int n)
{
    int low=0, mid=0, high = n-1;
    while(mid<=high)
    {
        int ele = arr[mid];
        if(ele==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(ele==1)
        {
            mid++;
        }
        else if(ele==2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {1,1,2,0,0,2,1,1};
    int n=8;
    dnfSort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}