#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n][n];
    int size = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];

            if(arr[i][j]!=0)
                size++;
        }
    }

    int sparse[3][size];
    int k = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]!=0)
                sparse[3][k] = arr[i][j];   
        }
    }

    // This sparse array contains only non zero values

    return 0;
}