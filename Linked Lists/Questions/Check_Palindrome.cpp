/*
    Approach 1: create an array and then check for palindrome

    Approach 2: find middle revrese list after middle then compare two parts
*/

#include<iostream>
#include<vector>
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

bool checkPalindrome1(Node* head)
{
    vector<int> v;

    Node* temp = head;

    while(temp!=NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }   

    int s=0, e=v.size()-1;

    while(s<=e)
    {
        if(v[s]!=v[e])
            return false;
        
        s++;
        e--;
    }

    return true;
}

int countElements(Node* head)
{
    int i = 0;

    while(head!=NULL)
    {
        i++;
        head = head->next;
    }

    return i;
}

Node* reverseByRecursion(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node* new_head = reverseByRecursion(head->next);

    head->next->next = head;
    head->next = NULL;

    return new_head;
}

bool checkPalindrome2(Node* head)
{
    int count = countElements(head);

    int from_ind = 0;
    int to_ind = 0;

    if(count%2)
    {
        from_ind = (count)/2 +1;
        to_ind = count/2;
    }
    else
    {
        from_ind = (count+1)/2;
        to_ind = (count-1)/2;
    }

    Node* from_node = head;

    while(from_ind--)
        from_node = from_node->next;

    Node* new_from_node = reverseByRecursion(from_node);
    Node* temp1 = head;
    Node* temp2 = new_from_node;
    while(to_ind--)
    {
        if(temp1->data != new_from_node->data)
            return false;
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;

}

int main()
{
    Node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,1);
    display(head);
    cout<<checkPalindrome2(head);
    return 0;
}