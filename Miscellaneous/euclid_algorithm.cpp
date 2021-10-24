/*
        Euclid to find GCD(Greatest Common Divisor) or HCF
*/

#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b)
{
    int c1 = max(a,b);
    int c2 = min(a,b);
    int c3 = c1%c2;
    while(c3!=0)
    {
        c1= c2;
        c2 = c3;
        c3 = c1%c2;
    }
    return c2;
}

int main()
{
    cout<<gcd(24,42)<<endl;
    return 0;
}