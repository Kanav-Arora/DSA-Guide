/*
    Check if a given number is of power 2

    n =   6 - 0110
    n-1 = 5 - 0101

    n & n-1 = 0100

    n =   8 - 1000      Even numbers have only one set bit
    n-1 = 7 - 0100

    n & n-1 = 0000

*/

#include<iostream>
using namespace std;

int checkPower(int n)
{
    return n && !(n & n-1);     // n && is used for the case when n=0; n-1 is not possible
}


int main()
{
    int n;
    cin>>n;
    cout<<checkPower(n)<<endl;
    return 0;
}