#include<iostream>
using namespace std;

class Node
{
    public:
        Node* prev;
        Node* next;
        int data;

        Node(int val)
        {
            prev = NULL;
            next = NULL;
            data = val;
        }
};

void insertAtHead(Node* &head, int data)
{
    Node* n = new Node(data);
    n->next = head;
    n->prev = NULL;
    head = n;
}

void deleteNode(Node* head, int pos)
{
    Node* to_delete = NULL;
    if(pos==0)
    {
        to_delete = head;
        head->next->prev = NULL;
        delete to_delete;
    }

    else
    {
        int i=0; 
        Node* temp = head;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        to_delete = temp->next;
        temp->next = temp->next->next;
        temp->next->next->prev = temp;
        delete to_delete;
    }
}

void display(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = new Node(5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    display(head);
    deleteNode(head,2);
    display(head);
    return 0;
}