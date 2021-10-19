/*

Companies: Amazon, Google, Facebook, Visa

                            Subarray With Given Sum

    Given an unsorted array A of size N of non-negative integers, find a continuous sub array which add to a given sum S.

*/




#include<iostream>
using namespace std;

int main()
{
    cout<<"Length of array: "<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Sum of subarray: "<<endl;
    int sum_sub;
    cin>>sum_sub;

    int start =0, end =0, sum=0;

    for(int i=0; i<n; i++)
    {
        sum=0;
        start = i;
        for(int j=i; j<n; j++)
        {
            end = j;
            sum+=arr[j];
            if(sum==sum_sub)
            {
                for(int ele=start; ele<=end; ele++)
                {
                    cout<<arr[ele]<<" ";
                }
                return 0;
            }
        }
    }

    return 0;
}