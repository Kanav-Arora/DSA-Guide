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
}

Node* Search(Node* root, int key)
{
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

Node* SearchRecursive(Node* root, int key)
{
    if(root==NULL)
        return NULL;

    if(key==root->data)
        return root;
    
    if(key>root->data)
        return SearchRecursive(root->right, key);
    
    else
        return SearchRecursive(root->left, key);
    
    return NULL;
}

int main()
{
    Node* root = NULL;
    input(root);

    // 10 7 15 5 9 17 16 19 -1

    int val;
    cin>>val;
    Node* ans = SearchRecursive(root, val);

    cout<<ans->data<<endl;
    return 0;
}