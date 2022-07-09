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

int KthGreatest(Node* root, int &i, int n, int k)
{
    if(root==NULL)
        return -1;

    int left = KthGreatest(root->left,i, n,k);

    if(left!=-1)
        return left;

    i++;

    if(i==n-k+1)
        return root->data;

    int right = KthGreatest(root->right,i, n,k);

    if(right!=-1)
        return right;

    return -1;
}


// Reverse Morris for reverse inorder traversal
int Morris(Node* root, int k)
{
    int i = 0;

    Node* curr = root;

    while(curr)
    {
        if(!curr->right)
        {
            i++;
            if(i==k)
                    return curr->data;
            curr = curr->left;
        }

        else
        {
            Node* temp = curr->right;

            while(temp->left && temp->left!=curr)
                temp = temp->left;

            if(temp->left==NULL)
            {
                temp->left = curr;
                curr = curr->right;
            }

            if(temp->left==curr)
            {
                temp->left = NULL;
                i++;
                if(i==k)
                    return curr->data;
                curr = curr->left;
            }
        }

    }

    return -1;

}

int main()
{
    Node* root = NULL;
    input(root);
    // 10 7 15 5 9 17 16 19 -1

    int i=0;
    cout<<KthGreatest(root,i,8,3);

    cout<<Morris(root,3);
    return 0;
}