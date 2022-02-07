#include<iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    public:
        void push(int x)
        {
            q2.push(x);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.swap(q2);
        }
        int pop()
        {
            if(q1.empty())
            {
                cout<<"Stack underflowed"<<endl;
                exit(0);
            }
            int ele = q1.front();
            q1.pop();
            return ele;
        }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}