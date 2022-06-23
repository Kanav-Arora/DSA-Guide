#include<iostream>
#include<queue>
#include<stack>
using namespace std;


void reverseFirstK(queue<int> &q, int k)
{
    stack<int> s;
    for(int i=0; i<k; i++)   
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    int t = q.size()-k;

    while(t--)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;

    q.push(3);
    q.push(2);
    q.push(1);
    q.push(6);
    q.push(5);

    reverseFirstK(q,3);

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}