#include<iostream>
#include<vector>
#include<queue>
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

void DFS(vector<Node*> vertices, int target, vector<bool> &visited, vector<int> &order)
{
    visited[target] = 1;
    order.push_back(target);
    Node* temp = vertices[target]->next;

    while(temp)
    {
        if(visited[temp->data]==0)
        {
            DFS(vertices, temp->data,visited, order); 
        }
        temp = temp->next;
    }
}

int main()
{
    int vertices;
    cin>>vertices; 
    int edges;
    cin>>edges;
    vector<Node*> v(vertices+1, NULL);
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

    cout<<endl<<"Graph Adjacency List created..."<<endl;

    for(int i=1; i<=vertices; i++)
    {
        cout<<"[ "<<v[i]->data<<" ]";

        Node* temp = v[i]->next;
        while(temp!=NULL)
        {
            cout<<" -> "<<temp->data;
            temp = temp->next;
        }

        cout<<endl;

    }

    cout<<endl;


    vector<int> order;
    vector<bool> visited(vertices+1, false);
    DFS(v,1,visited, order);

    for(int i : order)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

/*

8
16
1 2
1 3
2 1
2 5
2 6
3 1
3 4
3 7
4 3
4 8
5 2
6 2
7 3
7 8
8 4
8 7

*/