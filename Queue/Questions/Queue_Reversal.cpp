#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverse(queue<int> q)
{
    stack<int> s;

    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    return q;

}

void reverse2(queue<int> &q)
{
    if(q.empty())
        return;

    int val = q.front();
    q.pop();
    reverse2(q);
    q.push(val);
}


void display(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    display(q);
    queue<int> qr = reverse(q);
    display(qr);
    reverse2(q);
    display(q);
    return 0;
}