/*
    Search an element in rowise and columnwise sorted array with min time complexity.


    Linear approach will be of O(N^2) complexity
*/


#include<iostream>
using namespace std;

pair<int,int> Search_in_2d(int arr[][4], int m, int n, int target)
{
    int i=0, j=n-1;

    while(j>=0 && i>=0 && j<n && i<m)
    {
        if(target==arr[i][j])
            return {i,j};

        else if(target < arr[i][j])
            j--;
        else
            i++;
    }
}

int main()
{
    int arr[4][4] = {{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    pair<int,int> p =Search_in_2d(arr,4,4, 29);

    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}