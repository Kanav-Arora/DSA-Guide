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


// --------------------------------------------------Searching--------------------------------------------------------

bool search(Node* head, int val)
{
    if(head==NULL)
    {
        cout<<"Empty Linked List"<<endl;
        return 0;
    }

    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            cout<<"Element present in list"<<endl;
            return 1;
        }
        
        temp = temp->next;
    }
    cout<<"Element not present"<<endl;
    return 0;
}


// -------------------------------------------------------------------------------------------------------------------




int main()
{
    Node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    display(head);
    InsertAtHead(head,4);
    display(head);
    search(head,2);
    search(head,9);
    return 0;
}