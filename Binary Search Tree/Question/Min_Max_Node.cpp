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
        root = new Node(data);
        return root;
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

Node* MinVal(Node* root)
{
    Node* temp = root;

    while(temp->left!=NULL)
        temp = temp->left;
    
    return temp;
}

Node* MaxVal(Node* root)
{
    Node* temp = root;

    while(temp->right!=NULL)
        temp = temp->right;
    
    return temp;
}

int main()
{
    Node* root = NULL;
    input(root);

    printLevelOrder(root);

    // 10 7 15 5 9 17 16 19 -1

    cout<<MinVal(root)->data<<endl;
    cout<<MaxVal(root)->data<<endl;
    return 0;
}