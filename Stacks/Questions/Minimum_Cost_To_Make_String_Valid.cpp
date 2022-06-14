// Minimum Bracket Reversal

#include<iostream>
#include<stack>
using namespace std;

// no of open brace = no. of close brace

int minimumCost(string str)
{
    if(str.length()%2!=0)
        return -1;              // length is odd; therefore its not possible

    stack<char> s;
    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];

        if(ch=='{')
            s.push(ch);

        else
        {
            if(!s.empty() && s.top()=='{')
                s.pop();
            
            else
                s.push(ch);
        }
    }

    // stack contains invalid exp now

    int a=0, b=0;

    while(!s.empty())
    {
        char ch = s.top();

        if(ch=='{')
            b++;
        
        else if(ch=='}')
            a++;

        s.pop();
    }

    return ((a+1)/2 + (b+1)/2);
}

int main()
{
    cout<<minimumCost("{{}{");
    return 0;
}