#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        int num;
        cin>>num;
        arr[i] = num;
    }

    // int min=arr[0];
    int min = INT_MAX;                  // in the header file: climits, it gives the lowest possible integer value

    for(int i=0; i<n; i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }

    cout<<min<<endl;

    return 0;
}