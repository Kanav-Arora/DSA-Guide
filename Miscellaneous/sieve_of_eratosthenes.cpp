/*
    To print all prime numbers in given range
*/

#include<iostream>
using namespace std;

void primeNumbers(int n)
{
    bool arr[n+1];
    for(int i=0; i<n; i++)
    {
        arr[i] = true;
    } 
    arr[0]= false;
    arr[1]= false;
    
    for(int i=2; i<=n; i++)
    {
        if(i*i>n)
            break;

        if(arr[i]==true)
        {
            for(int j = i*i; j<=n; j+=i)
        {
            if(j%i==0)
            {
                arr[j] = false;
            }
        }
        }
    }

    for(int i=2; i<n; i++)
    {
        if(arr[i]==true)
            cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    primeNumbers(n);
    return 0;
}