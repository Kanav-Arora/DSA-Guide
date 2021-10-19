/*
    Maximum subarray sum possible

*/

#include<iostream>
#include<climits>
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
    int sum=0;
    int max_sum=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            sum=0;
            for(int k=i; k<=j; k++)
            {
                sum+=arr[k];
                
            }
            max_sum = max(sum,max_sum);
        }
    }
    cout<<max_sum;
    return 0;
}