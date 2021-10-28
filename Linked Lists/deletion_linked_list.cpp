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

void deletion(Node* &head, int val)
{
    if(head->next==NULL)
    {
        delete head;
        return;
    }

    else if(head==NULL)
    {
        return;
    }

    else if(head->data==val)
    {
        Node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }

    Node* temp = head;
    while(temp->next->data!=val)
    {
        temp=  temp->next;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void deletionByIndex(Node* &head, int pos)
{
    Node* temp = head;
    if(pos==0)
    {
        Node* to_delete = head;
        head = head->next;
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
    Node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    display(head);
    deletionByIndex(head,0);
    display(head);
    return 0;
}