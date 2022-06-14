#include<iostream>
using namespace std;


#define n 100

class TwoStack{
    int* arr;
    int top1, top2;

    public:
        TwoStack()
        {
            top1 = -1;
            top2 = n;
            arr = new int[n];
        }

        void push1(int x)
        {
            if(top1==n-1 || top1==top2-1)
            {
                cout<<"Stack1 Overflowed"<<endl;
                return;
            }

            arr[++top1] = x;
        }

        void push2(int x)
        {
            if(top2==0 || top2==top1+1)
            {
                cout<<"Stack2 Overflowed"<<endl;
                return;
            }

            arr[++top1] = x;
        }

        void pop1()
        {
            if(top1==-1)
            {
                cout<<"Stack 1 Underflowed"<<endl;
                return;
            }

            top1--;
        }

        void pop2()
        {
            if(top2==n)
            {
                cout<<"Stack 2 underflowed"<<endl;
                return;
            }

            top2--;
        }
};

int main()
{
    
    return 0;
}