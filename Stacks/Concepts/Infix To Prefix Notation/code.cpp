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

/*
Step 1: Reverse Infix String
Step 2: Perform Infix -> Postfix (with slight change: Now if precedence
                                should be strictly greater than char for it to be popped out of stack)
Step 3: Reverse Step 2 Output
*/

string reverseStringFunc(string s)
{
    string rev = "";
    for (auto each : s)
    {
        if (each == '(')
            rev = ')' + rev;
        else if (each == ')')
            rev = '(' + rev;
        else
            rev = each + rev;
    }
    return rev;
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
            if (each == '^')
            {
                while (!st.empty() && prec(st.top()) >= prec(each)) // Power operators follows associativity from right to left therefore must be applied
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && prec(st.top()) > prec(each)) // here > will be applied instead of >=
                {
                    ans += st.top();
                    st.pop();
                }
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

string infixToPrefix(string s)
{
    string rev1 = reverseStringFunc(s);
    cout << "Rev1 " << rev1 << endl;
    string res = infixToPostfix(rev1);
    cout << "Res " << res << endl;
    string rev2 = reverseStringFunc(res);
    cout << "Rev2 " << rev2 << endl;
    return rev2;
}

int main()
{
    cout << infixToPrefix("(A+B)*C-D+F") << endl;
    return 0;
}