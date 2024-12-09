#include<iostream>
using namespace std;

class Node{
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

static int idx = 0;

int search(int in[], int curr, int start, int end)
{
    for(int i=start; i<=end; i++)
    {
        if(in[i]==curr)
            return i;
    }
    return -1;
}

Node* buildTree(int pre[], int in[], int start, int end)
{
    if(start>end)
    {
        return NULL;
    }

    int curr = pre[idx];
    idx++;
    Node* node = new Node(curr);
    if(start==end)
        return node;
    int pos = search(in, curr, start, end);
    node->left = buildTree(pre, in, start, pos-1);
    node->right = buildTree(pre,in,pos+1,end);

    return node;
}

void inOrderPrint(Node* root)
{
    if(root==NULL)
        return;
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

int main()
{
    int preOrder[] = {1,2,4,3,5};
    int inOrder[] = {4,2,1,5,3};
    Node* root = buildTree(preOrder, inOrder, 0, 4);
    inOrderPrint(root);
    return 0;
}