#include <iostream>
#include <stack>
using namespace std;

// Costly Pop: While popping we are popping element from the last of the stack to get the FIFO functionality.
// But the same is done for Peek() also

class MyQueue
{
public:
    stack<int> st;
    MyQueue()
    {
    }

    int removeFromBottom(stack<int> &stk)
    {
        if (stk.size() == 1)
        {
            int bottom = stk.top();
            st.pop();
            return bottom;
        }
        int top = stk.top();
        stk.pop();
        int res = removeFromBottom(stk);
        stk.push(top);
        return res;
    }

    int peekFromBottom(stack<int> stk)
    {
        if (stk.size() == 1)
        {
            return stk.top();
        }
        int top = stk.top();
        stk.pop();
        int res = peekFromBottom(stk);
        stk.push(top);
        return res;
    }

    void push(int x)
    {
        st.push(x);
    }

    int pop()
    {
        return removeFromBottom(st);
    }

    int peek()
    {
        return peekFromBottom(st);
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