#include <iostream>
#include <stack>
using namespace std;

// Costly Push: While pushing we are pushing element to the last of the stack to get the FIFO functionality.

class MyQueue
{
public:
    stack<int> st;
    MyQueue()
    {
    }

    void insertAtBottom(stack<int> &stk, int val)
    {
        if (stk.empty())
        {
            stk.push(val);
            return;
        }

        int top = stk.top();
        stk.pop();
        insertAtBottom(stk, val);
        stk.push(top);
        return;
    }

    void push(int x)
    {
        insertAtBottom(st, x);
    }

    int pop()
    {
        int top = st.top();
        st.pop();
        return top;
    }

    int peek()
    {
        return st.top();
    }

    bool empty()
    {
        return st.empty();
    }
};

int main()
{
    return 0;
}