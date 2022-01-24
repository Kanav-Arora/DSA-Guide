#include<iostream>
#include<stack>
using namespace std;

void reverseString(string s)
{
    stack<char> std;
    for(int i=0; i<s.length(); i++)
    {
        std.push(s.at(i));
    }
    while(std.empty()==0)
    {
        cout<<std.top();
        std.pop();
    }
}

int main()
{
    string s = "Hey, My name is Kanav";
    reverseString(s);
    return 0;
}