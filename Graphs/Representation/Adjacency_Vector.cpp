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

int main()
{
    int vertices;
    cin>>vertices; 
    int edges;
    cin>>edges;
    vector<Node*> v(vertices, NULL);
    int v1,v2;
    while(edges--)
    {
        cin>>v1>>v2;
        if(v[v1]==NULL)
        {
            v[v1] = new Node(v1);
            InsertAtTail(v[v1],v2);
        }
        else
            InsertAtTail(v[v1],v2);
    }

    for(int i=0; i<vertices; i++)
    {
        cout<<"[ "<<v[i]->data<<" ]";

        Node* temp = v[i];
        while(temp!=NULL)
        {
            cout<<" -> "<<temp->data;
        }
    }
    return 0;
}