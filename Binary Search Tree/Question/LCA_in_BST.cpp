#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

Node* insert(Node* root, int data)
{
    if(root==NULL)
    {
        return new Node(data);
    }
    
    if(data>root->data)
        root->right = insert(root->right, data);

    else
        root->left = insert(root->left, data);

    return root;
}

void input(Node* &root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root = insert(root,data);
        cin>>data;
    }
}

void printLevelOrder(Node* root)
{
    if(root==NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node != NULL)
        {
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);

        }
        else if(!q.empty())
        {
            q.push(NULL);
        }

    }
    cout<<endl;
}

Node* LCA(Node* root, int n1, int n2)
{
    Node* temp = root;

    while(temp!=NULL)
    {
        if(n1<temp->data && temp->data<n2)
            return temp;
        
        else if(n1<temp->data && n2<temp->data)
            temp = temp->left;
        
        else
            temp = temp->right;
    }

    return NULL;
}

int main()
{
    Node* root = NULL;
    input(root);
    // 10 7 15 5 9 17 16 19 -1

    printLevelOrder(root);

    cout<<LCA(root,5,9)->data<<endl;
    return 0;
}