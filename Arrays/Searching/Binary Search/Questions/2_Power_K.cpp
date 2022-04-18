#include<iostream>
#include<cmath>
using namespace std;

int powerOfTwo(int arr[],int k)
{
    int value=0;
    int low=0, high=10, mid=0;
    while(low<high)
    {
        mid = low + (high-low)/2;
        if((((int)k/mid)*mid)>1)
        {
            int i = (k/mid)*mid;
            while(i--)
            {
                value = value + pow(2,mid);
            }
            k = k - (k/mid)*mid;
        }
        if(k<mid)
            high = mid-1;
    }
    return value;
}

int main()
{
    int k;
    cin>>k;
    int arr[11];
    for(int i=0; i<11; i++)
    {
        arr[i] = pow(2,i);
    }
    int ans = powerOfTwo(arr,k);
    cout<<ans<<endl;
    return 0;
}