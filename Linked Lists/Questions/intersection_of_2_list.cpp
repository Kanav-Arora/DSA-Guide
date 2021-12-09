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

int length(Node* head)
{
    int count=0;
    Node* temp = head;;
    while(temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int intersectionNode(Node* head1, Node* head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    Node* ptr1;
    Node* ptr2;
    int d = 0;
    if(l1>l2)
    {
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d)
    {
        ptr1 = ptr1->next;
        if(ptr1==NULL)
        {
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

void intersection(Node* head1, Node* head2, int pos)
{
    Node* temp = head1;
    for(int i=0; i<pos-1; i++)
    {
        temp = temp->next;
    }
    Node* temp2 = head2;
    while(temp2->next!=NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp->next;
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
    Node* head2 = NULL;
    InsertAtTail(head2,8);
    InsertAtTail(head2,9);
    InsertAtTail(head2,10);
    intersection(head, head2, 3);
    display(head2);
    cout<<intersectionNode(head,head2)<<endl;
    return 0;
}