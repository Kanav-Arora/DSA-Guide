#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
    int max_ind = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(arr[j]>arr[max_ind])
                max_ind = j;
        }
        swap(arr[i],arr[max_ind]);
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
    SelectionSort(arr,n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}