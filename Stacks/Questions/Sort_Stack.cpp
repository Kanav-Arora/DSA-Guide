#include<iostream>
#include<stack>
using namespace std;

void insertedSorted(stack<int> &s, int ele)
{
    if((ele>s.top() && !s.empty() )|| s.empty())
    {
        s.push(ele);
        return;
    }

    int val = s.top();
    s.pop();
    insertedSorted(s, val);
    s.push(val);

}

void sortStack(stack<int> &s)
{
    if(s.empty())
        return;

    int val = s.top();
    s.pop();
    sortStack(s);
    insertedSorted(s, val);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    sortStack(s);

    while(!s.empty())
    {
        int val = s.top();
        s.pop();
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}