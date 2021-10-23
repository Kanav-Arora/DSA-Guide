/*
        Set - 1
        Unset - 0

*/

#include<iostream>
using namespace std;


int setBit(int a, int pos)
{
    return (a | (1<<pos));
}

int main()
{
    cout<<setBit(19,3)<<endl;
    return 0;
}