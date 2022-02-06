#include<iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> s1;
    public:
        void push(int x)
        {
            s1.push(x);
        }

        /*
            Here we are using call stack to get the last element of our stack

            Pop function is different from that in costly dequeue method
        */

        int pop()
        {
            if(s1.empty())
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int x = s1.top();
            s1.pop();
            if(s1.empty())
            {
                return x;
            }
            int item = pop();
            s1.push(x);
            return item;
        }
};

int main()
{
    
    return 0;
}