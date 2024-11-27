#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postfixToInfix(string s)
{
    stack<string> st;
    for (auto each : s)
    {
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
            string exp = "(" + c2 + each + c1 + ")";
            st.push(exp);
        }
    }
    return st.top();
}

int main()
{
    cout << postfixToInfix("AB-DE+F*/") << endl; // Output: ((A-B)/((D+E)*F))
    return 0;
}