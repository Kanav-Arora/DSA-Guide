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

pair<int,int> Successor_Predecessor(Node* root, int key)
{
    Node* temp = root;
    int pred = -1;
    int succ = -1;


    // updating pred and succ because is key is the leaf node and left subtree and right
    // subtree doesn't exists
    while(temp->data!=key)
    {
        if(temp->data>key)
        {
            succ = temp->data;
            temp = temp->left;
        }

        if(temp->data<key)
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    Node* lt = root->left;
    Node* rt = root->right;

    while(lt->right!=NULL)
    {
        pred = lt->data;
        lt = lt->right;
    }

    while(rt->left!=NULL)
    {
        succ = rt->data;
        rt = rt->left;
    }

    return {pred,succ};
}

int main()
{
    Node* root = NULL;
    input(root);
    // 10 7 15 5 9 17 16 19 -1
    return 0;
}