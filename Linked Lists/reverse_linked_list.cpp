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

void reverseByIteration(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = head->next;

    while(next!=NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    head = curr;
}

Node* reverseByRecusion(Node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* new_head = reverseByRecusion(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return new_head;
}

int main()
{
    Node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    display(head);
    reverseByIteration(head);
    display(head);
    Node* new_head = reverseByRecusion(head);
    display(new_head);

    return 0;
}