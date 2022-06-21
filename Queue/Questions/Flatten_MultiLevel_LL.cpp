#include<iostream>
#include<queue>
using namespace std;

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* down;
        Node(int val)
        {
            data = val;
            next = NULL;
            down = NULL;
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

Node* AddLevel(Node* head, int ind, int val)
{
    Node* temp = head;
    Node* n = new Node(val);

    while(ind--)
    {
        temp = temp->next;
    }

    temp->down = n;

    return n;
}

void MultiLevel(Node* head)
{
    queue<Node*> q;

    Node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        if(temp->down!=NULL)
            q.push(temp->down);

        temp = temp->next;

        if(temp==NULL && !q.empty())
        {
            temp = q.front();
            q.pop();
        }
    }

    cout<<endl;
}

int main()
{
    Node* head = new Node(1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);

    Node* level_2_1 = AddLevel(head,0,6);
    Node* level_2_2 = AddLevel(head,3,9);

    InsertAtTail(level_2_1,7);
    InsertAtTail(level_2_1,8);

    InsertAtTail(level_2_2,10);

    MultiLevel(head);
    return 0;
}