#include<iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int count, int size)
{
    if(count==size/2)
    {
        s.pop();
        return;
    }
    int ele = s.top();
    s.pop();
    count++;
    solve(s,count,size);
    s.push(ele);
}

void deleteMidElement(stack<int> &s)
{
    int count = 0;
    solve(s,count, s.size());
}

void display(stack<int> s)
{
    while(!s.empty())
    {
        cout<<"|----> "<<s.top()<<endl;
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    deleteMidElement(s);
    display(s);
    return 0;
}