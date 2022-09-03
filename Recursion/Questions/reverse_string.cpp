#include<iostream>
#include<string>
using namespace std;

void reverse(string &str)
{
    if(str.length()==0)
    {
        return;
    }
    string ele = str.substr(0,1);
    str = str.substr(1);
    reverse(str);
    str = str+ele;
}

int main()
{
    string str;
    getline(cin,str);
    reverse(str);
    cout<<str;
    return 0;
}