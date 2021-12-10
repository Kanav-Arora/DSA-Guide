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

void insertAtHead(Node* &head, int data)
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
    n->next = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    head = n;
    
}

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

void deletionByIndex(Node* &head, int pos)
{
    Node* temp = head;
    if(pos==0)
    {
        Node* to_delete = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        delete to_delete;
        return;
    }
    int i=0;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    Node* to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
}

int main()
{
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,10);
    display(head);
    deletionByIndex(head,0);
    display(head);
    return 0;
}