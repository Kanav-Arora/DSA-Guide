#include<iostream>
using namespace std;

#define n 100

class Stack
{
    int* arr;
    int Top;

    public:
        Stack()
        {
            arr = new int[n];
            Top = -1;
        }

        void push(int x)
        {
            if(Top==n-1)
            {
                cout<<"Stack is full"<<endl;
                return;
            }
            Top++;
            arr[Top] = x;
        }
        void pop()
        {
            if(Top==-1)
            {
                cout<<"Stack is empyt"<<endl;
                return;
            }
            Top--;
        }
        bool empty()
        {
            if(Top==-1)
                return 1;
            return 0;
        }
        int top()
        {
            if(Top==-1)
            {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return arr[Top];
        }
        void display()
        {
            for(int i=Top; i>-1; i--)
            {
                cout<<"|___ "<<arr[i]<<endl;
            }
            cout<<endl;
        }
};


int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();
    st.pop();
    st.display();
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;
    return 0;
}