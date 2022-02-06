#include<iostream>
using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node* next;

        Node(T data)
        {
            this->data = data;
            next = NULL;
        }
};

template <class T>
class Queue{
    public:
        Node<T>* front = NULL;
        Node<T>* back = NULL;

        void enqueue(T x);
        void dequeue();
        bool empty();
        T peak();
        void display();
};

template <class T>
void Queue<T>::enqueue(T x)
{
    if(front==NULL)
    {
        Node<T>* n = new Node(x);
        front = n;
        back = n;
    }
    else
    {
        Node<T>* n = new Node(x);
        back->next = n;
        back = back->next;
    }
}

template <class T>
void Queue<T>::dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue underflowed"<<endl;
        return;
    }
    Node<T>* to_delete = front;
    front = front->next;
    delete to_delete;
}

template <class T>
bool Queue<T>::empty()
{
    if(front==NULL)
        return true;
    return false;
}

template <class T>
T Queue<T>::peak()
{
    if(front==NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    return front->data;
}

template <class T>
void Queue<T>::display()
{
    Node<T>* temp = front;
    cout<<"Front-> ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<" <-Back"<<endl;
}

int main()
{
    Queue<int> Q;
    Q.dequeue();
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.display();
    cout<<Q.empty()<<endl;
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.dequeue();
    cout<<Q.empty()<<endl;
    return 0;
}