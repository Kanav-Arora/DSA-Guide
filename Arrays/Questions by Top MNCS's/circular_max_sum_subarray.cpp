/*
                    Circular Max Sum Subarray

*/


#include<iostream>
#include<climits>
using namespace std;


int kadane(int arr[], int n)
{
    int curr_sum =arr[0];
    int max_sum = INT_MIN;
    for(int i=1; i<n; i++)
    {
        if(curr_sum<0)
            curr_sum=0;
        
        curr_sum+=arr[i];
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

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

    int wrapsum =0;
    int nonwrapsum = kadane(arr,n);
    int total_sum =0;
    for(int i=0; i<n; i++)
    {
        total_sum+=arr[i];
        arr[i] = -arr[i];

    }

    wrapsum = total_sum + kadane(arr,n);
    cout<<max(wrapsum,nonwrapsum)<<endl;

    return 0;
}