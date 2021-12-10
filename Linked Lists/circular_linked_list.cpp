#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
};

void insertAtTail(Node* head, int data)
{
    Node* temp = head;
    Node* n = new Node(data);
    if(head==NULL)
    {
        head = n;
    }
    if(head->next==NULL)
    {
        head->next = head;
    }
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(Node* head)
{
    Node* temp = head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
    
}

int main()
{
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    return 0;
}