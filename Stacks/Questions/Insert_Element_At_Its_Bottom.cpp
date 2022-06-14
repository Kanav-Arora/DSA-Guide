#include<iostream>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int> &s, int ele)
{
    if(s.empty()==1)
    {
        s.push(ele);
        return;
    }

    int val = s.top();
    s.pop();
    InsertAtBottom(s,ele);
    s.push(val);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    InsertAtBottom(s,0);

    while(!s.empty())
    {
        int w = s.top();
        cout << w<<" ";
        s.pop();
    }

    return 0;
}