#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    int sum =0;
    for(int i=0; i<n; i++)
    {   int subsum =0;
        int till = i+1;
        while(till<=n)
        {
        for(int j=i; j<till; j++)
        {
            subsum+=arr[j];
        }
        till++;
        }
        sum+=subsum;
    }

    cout<<"Sum of all possible subarrays: "<<sum;
    return 0;
}