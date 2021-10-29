#include<iostream>
using namespace std;

int power(int n, int pow)
{
    if(pow==0)
    {
        return 1;
    }
    return n*power(n,pow-1);
}

int main()
{
    int n,pow;
    cin>>n>>pow;
    cout<<power(n,pow)<<endl;
    return 0;
}