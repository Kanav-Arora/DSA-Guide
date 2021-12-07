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

bool detectCycle(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow  = slow->next;
        fast = fast->next->next;

        if(fast==slow)
            return true;
    }

    return false;
}

void makeCycle(Node* head, int pos)
{
    Node* temp = head;
    Node* n = NULL;
    int count=0;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            n = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = n;
}

void removeCycle(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    Node* meet = NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast==slow)
        {
            meet = slow;
            fast= head;
            break;
        }
    }
    while(fast->next!=slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
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
    makeCycle(head,2);
    if(detectCycle(head))
        cout<<"Cycle exists"<<endl;
    else
        cout<<"Cycle doesn't exists"<<endl;
    removeCycle(head);
    display(head);
    if(detectCycle(head))
        cout<<"Cycle exists"<<endl;
    else
        cout<<"Cycle doesn't exists"<<endl;
    
    return 0;
}