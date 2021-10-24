#include<iostream>
using namespace std;


int unsetBit(int a, int pos)
{
    return (a & (~(1<<pos)));
}

int main()
{
    cout<<unsetBit(19,1)<<endl;
    return 0;
}