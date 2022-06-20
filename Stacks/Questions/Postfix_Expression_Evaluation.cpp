#include<iostream>
#include<stack>
using namespace std;

int Postfix(string s)
{
    stack<int> stk;

    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i];
        if(ch>='0' && ch<='9')
        {
            int num = ch - '0';
            stk.push(num);
        }

        else
        {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            int res = 0;

            if(ch=='+')
                res = num1+num2;
            else if(ch=='-')
                res = num1 - num2;
            else if(ch =='*')
                res = num1*num2;
            else if(ch=='/')
                res = num1/num2;

            stk.push(res);

        }
    }

    return stk.top();
}

int main()
{
    cout<<Postfix("46+2/5*7+")<<endl;


    return 0;
}