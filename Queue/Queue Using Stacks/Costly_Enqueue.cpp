#include<iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;

    public:
        void push(int x)
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            //  here time complexity is O(N)
        }
        int pop()
        {
            if(s1.empty())
            {
                cout<<"Queue underflowed"<<endl;
                exit(0);
            }
            int ele = s1.top();
            s1.pop();
            return ele;

            // here time complexity is O(1)
        }
};


int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    return 0;
}