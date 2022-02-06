#include<iostream>
#include <stack>
using namespace std;


class Queue{
    stack<int> s1;
    stack<int> s2;

    public:
        void push(int x)
        {
            s1.push(x);
        }

        void pop()
        {
            if(s1.empty() && s2.empty())
            {
                cout<<"Queue underflowed"<<endl;
                return;
            }
            else if(s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            s2.pop();
        }
        bool empty()
        {
            if(s1.empty() && s2.empty())
                return 1;
            return 0;
        }
        void top()
        {
            if(s1.empty() && s2.empty())
            {
                cout<<"Queue is empty"<<endl;
                return;
            }
            else if(s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            s2.top();
        }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.empty()<<endl;
    return 0;
}