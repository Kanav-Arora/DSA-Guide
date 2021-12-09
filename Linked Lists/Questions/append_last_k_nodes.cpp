/*
        Append last k nodes to head of linked list

*/

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

void InsertAtHead(Node* &head, int val)
{
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void InsertAtIndex(Node* &head, int index, int val)
{
    Node* n = new Node(val);

    if(head==NULL && index==0)
    {
        head =n;
        return;
    }
    else if(head==NULL && index!=0)
    {
        return;
    }
    int i=0;
    Node* next_node = head;
    Node* prev_node = head;
    while(i!=index)
    {
        prev_node = next_node;
        next_node = next_node->next;
        i++;
    }
    prev_node->next = n;
    n->next = next_node;
}

void InsertAtTail(Node* &head, int val)
{
    Node *n = new Node(val);

    Node* temp = head;

    if(head==NULL)
    {
        head =n;
        return;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = n;


}

void display(Node* head)
{
    if(head==NULL)
    {
        cout<<"Empty linked list";
    }
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

int length(Node* head)
{
    int count=0;
    Node* temp = head;
    while(temp!=NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void appendKNodes(Node* &head, int k)
{
    Node* temp = head;
    for(int i=0; i<length(head)-k-1; i++)
    {
        temp = temp->next;
    }
    Node* new_tail = temp;
    Node* new_head = temp->next;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    new_tail->next = NULL;
    head = new_head;
}

int main()
{
    Node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    display(head);
    InsertAtHead(head,4);
    display(head);
    InsertAtIndex(head,2,4);
    display(head);
    appendKNodes(head,2);
    display(head);
    return 0;
}