#include<iostream>
#include<queue>
#include<vector>
#include<climits>
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

// Approach 1

void inOrder(Node* root, vector<int> &v)
{
    if(root==NULL)
        return;

    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right,v);
}

bool ValidBST(Node* root)
{
    vector<int> v;

    inOrder(root,v);

    int size = v.size();

    for(int i=1; i<size-1; i++)
    {
        if(v[i]<v[i-1])
            return false;
    }
    return true;
}

// Approach 2

bool ValidBST_2(Node* root, pair<int,int> p = {INT32_MIN,INT32_MAX})
{   
    if(root==NULL)
        return true;

    if(root->data>p.first && root->data<p.second)
    {
        bool lt = ValidBST_2(root->left,{p.first,root->data});
        bool rt = ValidBST_2(root->right,{root->data, p.second});

        if(lt && rt)
            return true;
        
        else
            return false;
    }

    return false;
}

int main()
{
    Node* root = NULL;
    input(root);
    // 10 7 15 5 9 17 16 19 -1
    cout<<ValidBST_2(root)<<endl;
    return 0;
}