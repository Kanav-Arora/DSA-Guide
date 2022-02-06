#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
    int curr_ele = 0;
    for(int i=1; i<n; i++)
    {
        curr_ele = arr[i];
        int j = i-1;
        while(arr[j]<arr[j+1] && j>=0)
        {
            swap(arr[j],arr[j+1]);
            j--;
        }
        arr[j+1] = curr_ele;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    InsertionSort(arr,n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}