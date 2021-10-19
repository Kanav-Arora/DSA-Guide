/*

Companies: Accolite, Amazon, Samsung, Snapdeal

                        Smallest Positive Missing Number

    You are given an arr[] of N integers including 0. The task is to find the smallest positive 
    number missing from the array. 

    Input:
    6
    0 -9 1 3 -4 5

    Output:
    2

*/


#include<iostream>
using namespace std;

int main()
{
    const int size = 1e6;
    bool check[size];
    for(int i=0; i<size; i++)
    {
        check[i] = false;
    }
    cout<<"Length of array: "<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(int i=0; i<n; i++)
    {
        int num = arr[i];
        if(num>0)
        {
            check[num] = true;
        }
    }
    check[0] = true;
    for(int j=0; j<size; j++)
    {
        if(check[j]==false)
        {
            cout<<"Smallest missing integer: "<<j<<endl;
            break;
        }
    }
    return 0;
}