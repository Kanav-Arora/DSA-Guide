/*
        Merge Sort in LL
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

Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow  = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right)
{

    if(left==NULL)
        return right;
    
    if(right==NULL)
        return left;

    Node* f = left;
    Node* s = right;
    Node* result = new Node(-1);
    Node* temp = result;

    while(f!=NULL && s!=NULL)
    {
        if(f->data<s->data)
        {
            temp->next = f;
            temp  = temp->next;
            f = f->next;
        }

        else
        {
            temp->next = s;
            temp  = temp->next;
            s = s->next;
        }
    }

    while(f!=NULL)
    {
        temp->next = f;
        temp  = temp->next;
        f = f->next;
    }

    while(s->next)
    {
        temp->next = s;
        temp  = temp->next;
        s = s->next;
    }

    return result->next;
}

Node* mergeSorting(Node* head)
{
    //base case

    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;


    // recursive calls
    left = mergeSorting(left);
    right = mergeSorting(right);

    Node* result = merge(left,right);

    return result;
}

int main()
{
    Node* head = NULL;
    InsertAtTail(head, 10);
    InsertAtTail(head, 9);
    InsertAtTail(head, 8);
    InsertAtTail(head, 7);
    InsertAtTail(head, 6);
    InsertAtTail(head, 5);
    InsertAtTail(head, 4);

    Node* result = mergeSorting(head);
    display(result);
    return 0;
}