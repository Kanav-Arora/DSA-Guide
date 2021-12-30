#include<iostream>
using namespace std;

int main()
{
    int arr[4];
    arr[0] = 0;
    arr[1] = 10;
    arr[2] = 20;
    arr[3] = 30;

    cout<<arr[3]<<endl;

    int array[4] = {0,100,200,300};
    cout<<array[3]<<endl;

    int one[5] = {1};
    int n= 5;
    for(int i=0; i<n; i++)
    {
        cout<<one[i]<<" ";
    }
    cout<<endl;

    return 0;
}