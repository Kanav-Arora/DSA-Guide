#include<iostream>
using namespace std;


bool isSafe(int** arr, int x, int y, int n)
{
    for(int i=0; i<x; i++)
    {
        if(arr[i][y]==1)
        {
            return false;
        }
    }
    for(int i=x,j=y; i>=0 and j<n; i--,j++)
    {
        if(arr[i][j]==1)
        {
            return false;
        }
    }
    for(int i=x,j=y; i>=0 and j>=0; i--,j--)
    {
        if(arr[i][j]==1)
        {
            return false;
        }
    }
    return true;
}

int queen(int** arr, int x, int n)
{
    if(x>=n)
    {
        return true;
    }

    for(int col=0; col<n; col++)
    {
        if(isSafe(arr,x,col,n))
        {
            arr[x][col] = 1;

            if(queen(arr,x+1,n))
            {
                return true;
            }

            arr[x][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = new int[n];
    } 
    queen(arr,0,n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}