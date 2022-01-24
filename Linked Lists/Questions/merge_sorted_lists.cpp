/*
    We have 2 sorted linked list and we need to merge them to make a new
    linked list
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


Node* mergeLists(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* new_head = NULL;
    if(head1->data>head2->data)
    {
        new_head = head2;
        temp2 = temp2->next;
    }
    else
    {
        new_head = head1;
        temp1 = temp1->next;
    }
    
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data>temp2->data)
        {
            cout<<temp2->data<<" ";
            InsertAtTail(new_head,temp2->data);
            temp2 = temp2->next;
        }
        else
        {
            cout<<temp1->data<<" ";
            InsertAtTail(new_head, temp1->data);
            temp1 = temp1->next;
        }
    }

    while(temp1!=NULL)
    {
        InsertAtTail(new_head, temp1->data);
        temp1 = temp1->next;
    }

    while(temp2!=NULL)
    {
        InsertAtTail(new_head, temp2->data);
        temp2 = temp2->next;
    }

    return new_head;
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    InsertAtTail(head1,1);
    InsertAtTail(head1,4);
    InsertAtTail(head1,5);
    InsertAtTail(head1,7);
    InsertAtTail(head2,2);
    InsertAtTail(head2,3);
    InsertAtTail(head2,6);
    display(head1);
    display(head2);
    Node* new_head = mergeLists(head1,head2);
    display(new_head);
    return 0;
}