#include<iostream>
#include<stack>
using namespace std;

#define n 100

class MinStack{
    public:
        int* s;
        int* ss;
        int top;
        int min_top;

        MinStack()
        {
            s = new int[n];
            ss = new int[n];

            top = -1;
            min_top = -1;
        }

        void push(int x)
        {
            if(top==n-1)
            {
                cout<<"Stack Overflowed"<<endl;
                return;
            }
            top++;
            s[top] = x;
            
            
            if(x>=ss[min_top] && min_top!=-1) 
                return;

            min_top++;
            ss[min_top] = x;
        }

        void pop()
        {
            if(top==0)
            {
                cout<<"Stack Underflowed"<<endl;
                return;
            }
            
            if(ss[min_top]==s[top])
                min_top--;
            
            top--;

        }

        int val_top()
        {
            return s[top];
        }

        int val_min_top()
        {
            return ss[min_top];
        }
};

int main()
{
    MinStack m;
    m.push(18);
    m.push(19);
    cout<<m.val_min_top()<<endl;
    m.push(29);
    cout<<m.val_min_top()<<endl;
    m.push(15);
    cout<<m.val_min_top()<<endl;
    m.pop();
    cout<<m.val_min_top()<<endl;
    m.push(16);
    cout<<m.val_min_top()<<endl;
    return 0;
}