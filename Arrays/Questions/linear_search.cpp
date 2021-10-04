#include<iostream>
using namespace std;

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
    bool flag = true;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==ele)
        {
            flag = false;
            cout<<"Element present in array at index: "<<i<<endl;
        }
    }

    if(flag==true)
    {
        cout<<"Element not present in array"<<endl;
    }


    return 0;
}