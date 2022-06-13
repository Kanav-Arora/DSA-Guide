/*
    Check whether a series of parenthesis is valid or not

    {} - valid
    {()} - valid
    {[} - invalid

*/

#include<iostream>
#include<stack>
using namespace std;


bool isValid(string expr)
{
    stack<char> s;

    for(int i=0; i<expr.length(); i++)
    {
        char ch = expr[i];

        if(ch=='{' || ch=='(' || ch=='[')
            s.push(ch);

        else
        {
            if(s.empty()==1)
                return 0;
            else
            {
                char top = s.top();

                if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') )
                {
                    s.pop();
                }
            }

        }
    }

    if(s.empty()==1)
        return 1;
    
    return 0;
}

int main()
{
    cout<<isValid("{()}");
    return 0;
}