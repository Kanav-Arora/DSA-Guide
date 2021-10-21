#include<iostream>
using namespace std;

int main()
{
    char arr[100] = "kanav";
    int i=0;
    while(arr[i]!='\0')
    {
        cout<<arr[i];
        i++;
    }
    cout<<endl;
    cout<<"Enter any word"<<endl;
    cin>>arr;
    cout<<arr;
    return 0;
}