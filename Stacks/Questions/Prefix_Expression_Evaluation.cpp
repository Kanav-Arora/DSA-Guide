#include<iostream>
#include<stack>
using namespace std;


int Prefix(string s)
{
    stack<int> stk;

    for(int i=s.length()-1; i>=0; i--)
    {
        char ch = s[i];
        if(ch>='0' && ch<='9')
        {
            int num = ch - '0';
            stk.push(num);
        }

        else
        {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
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
    cout<<Prefix("-+7*45+20")<<endl;
    return 0;
}