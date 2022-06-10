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

Node* mergeSortedList(Node* head1, Node* head2)
{
    if(head1==NULL)
        return head2;
    
    if(head2==NULL)
        return head1;
    
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1->next!=NULL && temp2->next!=NULL)
    {
        if(temp2->data > temp1->data && temp2->data<temp1->next->data)
        {
            Node* to_add = temp2;
            temp2 = temp2->next;
            to_add->next = temp1->next;
            temp1->next = to_add;
        }
        else
        {
            temp1 = temp1->next;
        }
    }

    if(temp2!=NULL)
        temp1->next = temp2;
    return head1;
}

int main()
{
    Node* head1 = NULL;
    InsertAtTail(head1,1);
    InsertAtTail(head1,2);
    InsertAtTail(head1,3);
    display(head1);

    Node* head2 = NULL;
    InsertAtTail(head2,4);
    InsertAtTail(head2,5);
    InsertAtTail(head2,6);
    display(head2);

    Node* new_head = mergeSortedList(head1, head2);
    display(new_head);
    return 0;
}