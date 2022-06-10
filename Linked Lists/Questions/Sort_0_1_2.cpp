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


void Approach1(Node* head)
{
    Node* temp = head;

    int zeroes  = 0, ones = 0, twos = 0;

    while(temp != NULL)
    {
        if(temp->data == 0)
            zeroes++;
        else if(temp->data == 1)
            ones++;
        else twos++;

        temp = temp->next;
    }

    temp = head;

    while(zeroes--)
    {
        temp->data = 0;
        temp = temp->next;
    }

    while(ones--)
    {
        temp->data = 1;
        temp = temp->next;
    }

    while(twos--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}


// some error

// void populate(Node* &tail, Node* curr)
// {
//     tail->next = curr;
//     tail = curr;
// }

// Node* Approach2(Node* &head)
// {
//     Node* zerohead = new Node(-1);
//     Node* zerotail = zerohead;
//     Node* onehead = new Node(-1);
//     Node* onetail = onehead;
//     Node* twohead = new Node(-1);
//     Node* twotail  = twohead;

//     Node* curr = head;

//     while(curr!=NULL)
//     {
//         int value = curr->data;

//         if(value==0)
//             populate(zerotail, curr);

//         if(value==1)
//             populate(onetail, curr);

//         if(value==2)
//             populate(twotail, curr);

//         curr = curr->next;
//     }

//     display(zerohead);

//     //merge 3 LLs
//     if(onehead->next==NULL)
//         zerotail->next = twohead->next;
//     else
//     {
//         zerotail->next = onehead->next;
//     }
    
//     onetail->next  = twohead->next;
//     twotail->next = NULL;

//     delete zerohead;
//     delete onehead;
//     delete twohead;

//     return zerohead->next;
// }

int main()
{
    Node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,1);
    InsertAtTail(head,0);
    InsertAtTail(head,2);
    InsertAtTail(head,1);
    InsertAtTail(head,1);
    InsertAtTail(head,0);
    InsertAtTail(head,0);
    InsertAtTail(head,2);
    InsertAtTail(head,2);
    InsertAtTail(head,1);
    display(head);
    Approach1(head);
    display(head);
    return 0;
}