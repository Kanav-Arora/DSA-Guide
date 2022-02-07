#include<iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    public:
        void push(int x)
        {
            q1.push(x);
        }
        int pop()
        {
            if(q1.empty())
            {
                cout<<"Stack underflowed"<<endl;
                exit(0);
            }
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();
            q1.pop();
            q1.swap(q2);
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