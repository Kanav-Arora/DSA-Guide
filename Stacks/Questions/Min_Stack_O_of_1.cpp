#include<iostream>
#include<climits>
using namespace std;

#define n 100

class Stack
{
    int* arr;
    int Top;
    int minElement;

    public:
        Stack()
        {
            arr = new int[n];
            Top = -1;
            minElement = INT_MIN;
        }

        void push(int x)
        {
            if(Top==n-1)
            {
                cout<<"Stack is full"<<endl;
                return;
            }

            if(minElement==INT_MIN)
            {
                Top++;
                arr[Top] = x;
                minElement = x;
            }

            if(x<minElement)
            {
                Top++;
                arr[Top] = 2*x - minElement;
                minElement = x;
            }
        }

        void pop()
        {
            if(Top==-1)
            {
                cout<<"Stack is empyt"<<endl;
                return;
            }
            
            if(arr[Top]<minElement)
            {
                minElement = 2*minElement - arr[Top];
                Top--;
            }
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

        int valMinElement()
        {
            return minElement;
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
    st.push(5);
    cout<<st.valMinElement()<<endl;
    st.push(3);
    cout<<st.valMinElement()<<endl;
    st.display();
    st.pop();
    cout<<st.valMinElement()<<endl;
    return 0;
}