#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postfixToInfix(string s)
{
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char each = s[i];
        if ((int(each) >= 48 && int(each) <= 57) || (int(each) >= 65 && int(each) <= 90) || (int(each) >= 97 && int(each) <= 122))
        {
            string s;
            st.push(s + each);
        }
        else
        {
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();
            string exp = "(" + c1 + each + c2 + ")"; // In this we'll do c1 <operation> c2
            st.push(exp);
        }
    }
    return st.top();
}

int main()
{
    cout << postfixToInfix("*+PQ-MN") << endl; // Output: ((P+Q)*(M-N))
    return 0;
}