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
    int mini = INT_MAX;                  // in the header file: climits, it gives the lowest possible integer value

    for(int i=0; i<n; i++)
    {
        // if(arr[i]<mini)
        // {
        //     mini=arr[i];
        // }

        //* else we can use below function
        mini = min(mini, arr[i]);
    }

    cout<<mini<<endl;

    return 0;
}