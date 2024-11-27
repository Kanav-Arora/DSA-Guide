#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return -1;
    }
    return -1;
}

string infixToPostfix(string s)
{
    string ans = "";
    stack<char> st;
    for (auto each : s)
    {
        if ((int(each) >= 48 && int(each) <= 57) || (int(each) >= 65 && int(each) <= 90) || (int(each) >= 97 && int(each) <= 122))
        {
            ans += each;
        }
        else if (each == '(')
            st.push(each);
        else if (each == ')')
        {
            while (!st.empty())
            {
                if (st.top() == '(')
                {
                    st.pop();
                    break;
                }
                ans += st.top();
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(each))
            {
                ans += st.top();
                st.pop();
            }
            st.push(each);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    cout << infixToPostfix("a+b*(c^d-e)") << endl; // output: abcd^e-*+
    return 0;
}