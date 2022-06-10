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


void RemoveDuplicates(Node* head)
{
    Node* curr = head;

    while(curr->next!=NULL && curr!=NULL)
    {
        Node* temp = curr->next;

        while(temp->next!=NULL)
        {
            if(temp->next->data==curr->data)
            {
                Node* to_delete = temp->next;
                temp->next = temp->next->next;
                delete to_delete;
            }
            else
            {
                temp = temp->next;
            }
        }

        curr = curr->next;
    }
}

int main()
{
    Node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,5);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,2);
    InsertAtTail(head,2);
    display(head);
    RemoveDuplicates(head);
    display(head);
    return 0;
}