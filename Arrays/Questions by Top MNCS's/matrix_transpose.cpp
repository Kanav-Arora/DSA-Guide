/*
                    Matrix Transpose
    
    You are given a square matrix with number of rows. Find the transpose
    of given matrix.

*/

#include<iostream>
using namespace std;

int main()
{
    int n=5;
    int arr[5][5] = {{1,2,2,2,2},{0,1,2,2,2},{0,0,1,2,2},{0,0,0,1,2},{0,0,0,0,1}};

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int swap = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = swap;
        }
    }

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