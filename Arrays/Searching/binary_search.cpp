#include<iostream>
using namespace std;

int binary_search(int arr[], int num, int key)
{
    int s=0;
    int e = num;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
        {
            e = mid-1;
        }
        else if(arr[mid]<key)
        {
            s = mid+1;
        }

    }
    return -1;

}

int main()
{
    cout<<"Number of elements in array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        int num;
        cin>>num;
        arr[i] = num;
    }

    cout<<"Enter element to search"<<endl;
    int ele;
    cin>>ele;

    int val  = binary_search(arr, n, ele);
    cout<<val<<endl;
    return 0;
}