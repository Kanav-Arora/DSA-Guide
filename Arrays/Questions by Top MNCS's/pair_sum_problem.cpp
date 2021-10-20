#include<iostream>
#include<algorithm>
using namespace std;



//* worst case complexity: O(n^2)

bool pairs(int arr[], int n, int k)         
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            if(arr[i]+arr[j]==k)
            {
                return true;
            }
        }
    }
    return false;
}


//* Complexity:     O(n)
bool pairs_2(int arr[], int n, int k)
{
    sort(arr,arr+n);
    int low = 0;
    int high = n-1;

    while(arr[low] + arr[high] != k && low<high)
    {
        int val = arr[low] + arr[high];
        if(val<k)
            low++;
        if(val>k)
            high--;
        if(val==k)
            return true;
    }
    return false;
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

    cout<<"Enter value k: "<<endl;
    int k;
    cin>>k;

    cout<<pairs(arr,n,k)<<endl;

    return 0;
}