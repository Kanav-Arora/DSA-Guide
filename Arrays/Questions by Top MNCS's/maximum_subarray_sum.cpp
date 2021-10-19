/*
    Maximum subarray sum possible
*/

#include<iostream>
#include<climits>
using namespace std;

// ------------------------------------------------------------------------     //

//*                     Kadane's Algorithm

void func1(int arr[], int n)
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
    cout<<"Max sum using Kadane's Approach: "<<max_sum<<endl;
}


// ------------------------------------------------------------------------     //


//*                     Cumulative Sum Approach
// reduce time complexity

void func2(int arr[],int n)
{
    
    int cumm_sum[n+1];
    cumm_sum[0] = 0;

    for(int i=1; i<=n; i++)
        cumm_sum[i] = cumm_sum[i-1] + arr[i-1];
    
    int max_sum = INT_MIN;
    int sum =0;
    for(int i=1; i<=n; i++)
    {
        sum=0;
        for(int j=0; j<i; j++)
        {
            sum = cumm_sum[i] - cumm_sum[j];
            max_sum = max(max_sum, sum);
        }
    }

    cout<<"Max Sum using cumulative approach: "<<max_sum<<endl;
}

// ------------------------------------------------------------------------     //


void func3(int arr[], int n)
{
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
    cout<<"Max Sum using normal approach: "<<max_sum<<endl;
}

// ------------------------------------------------------------------------     //


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

    func1(arr,n);
    func2(arr,n);
    func3(arr,n);
    return 0;
}