#include<iostream>
using namespace std;

#define n 100 

class Queue{
    public:
        int front;
        int back;
        int* arr;

        Queue()
        {
            front = -1;
            back = -1;
            arr = new int[n];
        }
};

void Enqueue(Queue &q, int x)
{
    if(q.front==-1)
        q.front++;
    
    if(q.back==n-1)
        cout<<"Queue overflow exception"<<endl;

    q.back++;
    q.arr[q.back] = x;
}

void Dequeue(Queue &q)
{
    if(q.front==q.back)
    {
        cout<< "Queue underflow exception"<<endl;
        return;
    }
    q.front++;
}

bool Empty(Queue &q)
{
    if(q.front==-1 || q.front>q.back)
        return true;
    return false;
}

int Peak(Queue &q)
{
    if(q.front==-1 || q.front>q.back)
    {
        cout<<"No elements found; Queue is empty"<<endl;
        return -1;
    }

    return q.arr[q.front];
}


int main()
{
    Queue q;
    cout<<Peak(q)<<endl;
    Enqueue(q,1);
    Enqueue(q,2);
    Enqueue(q,3);
    cout<<Peak(q)<<endl;
    Dequeue(q);
    cout<<Peak(q)<<endl;
    cout<<Empty(q)<<endl;
    return 0;
}