#include<iostream>
#include<stack>
using namespace std;


void InsertAtBottom(stack<int> &std, int ele)
{
    if(std.empty()==1)
    {
        std.push(ele);
        return;
    }
    else
    {
        int val = std.top();
        std.pop();
        InsertAtBottom(std,ele);
        std.push(val);
    }
}

void reverseStack(stack<int> &std)
{
    if(std.empty()==1)
        return;
    int ele = std.top();
    std.pop();
    reverseStack(std);              // using call stack will result in giving same stack
    InsertAtBottom(std,ele);
}

int main()
{
    stack<int> std;
    for(int i=0; i<5; i++)
    {
        std.push(i);
    }
    reverseStack(std);
    for(int i=0; i<5; i++)
    {
        cout<<std.top()<<" ";
        std.pop();
    }
    return 0;
}