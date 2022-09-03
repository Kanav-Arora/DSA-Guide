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

vector<int> BFS(vector<Node*> vertices, int start)
{
    queue<int> q;
    vector<int> visited(vertices.size()+1,0);

    q.push(start);
    visited[start] = 1;

    vector<int> order;

    while(!q.empty())
    {
        int size = q.size();

        for(int i=0;i<size; i++)
        {
            int front = q.front();
            q.pop();
            order.push_back(front);
            Node* temp = vertices[front]->next;

            while(temp!=NULL)
            {
                if(visited[temp->data]==0)
                {
                    visited[temp->data] = 1;
                    q.push(temp->data);
                }
                temp = temp->next;
            }
        }
    }

    return order;
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


    vector<int> order = BFS(v,6);

    for(int i : order)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}


/*

9
18
1 2
1 6
2 1
2 3
2 4
3 2
4 2
4 5
5 4
5 8
6 1
6 7
6 9
7 6
7 8
8 5
8 7
9 6

*/