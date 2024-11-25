#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    // must have a constant
    int arr[50];
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
    // .Another approach using iterator
    // this return an iterator so use a pointer
    int minElement=*std::min_element(arr,arr+n);
    cout<<minElement<<endl;
    return 0;
}