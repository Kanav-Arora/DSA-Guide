#include<iostream> 
#include<queue>
#include<stack>
using namespace std;

queue<int> Interleave(queue<int> q)
{
    int t = q.size()/2;
    queue<int> qt;

    while(t--)
    {
        qt.push(q.front());
        q.pop();
    }

    while(!qt.empty())
    {
        q.push(qt.front());
        qt.pop();

        q.push(q.front());
        q.pop();
    }

    return q;
}




queue<int> Interleave2(queue<int> q)
{
    stack<int> s;

    int t = q.size()/2;

    while(t--)
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    t = q.size()/2;

    while(t--)
    {
        q.push(q.front());
        q.pop();
    }

    t = q.size()/2;

    while(t--)
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())
    {
        q.push(s.top());
        q.push(q.front());
        s.pop();
        q.pop();
    }

    return q;
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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    queue<int> ans = Interleave2(q);

    display(ans);
    return 0;
}