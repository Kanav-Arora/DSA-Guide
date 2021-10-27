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
    Node* prev_node = head;
    Node* forward_node = head;
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            forward_node = temp->next;  
            /*
                    Here,   lets assume if block executes after nth iteration
                        forward_node = temp->next;
                        temp = {current node}
                        prev_node = temp (n-1)th iteration
            */
            break;
        }
        prev_node = temp;
        temp=  temp->next;

    }
    prev_node->next = forward_node;
    delete temp;
}

int main()
{
    Node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    display(head);
    deletion(head,2);
    display(head);
    return 0;
}