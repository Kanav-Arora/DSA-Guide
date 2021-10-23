#include<iostream>
using namespace std;

int getBit(int a, int pos)
{
    return ((a & (1<<pos))!=0);
}

int main()
{
    cout<<getBit(19,3)<<endl;
    return 0;
}