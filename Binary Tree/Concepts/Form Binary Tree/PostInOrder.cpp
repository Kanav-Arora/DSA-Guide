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

static int idx = 4;

int search(int in[], int curr, int start, int end)
{
    for(int i=start; i<=end; i++)
    {
        if(in[i]==curr)
            return i;
    }
    return -1;
}

Node* buildTree(int postOrder[], int inOrder[], int start, int end)
{

    if(start>end)
    {
        return NULL;
    }

    int val = postOrder[idx];
    idx--;

    Node* curr = new Node(val);
    if(start==end)
    {
        return curr;
    }

    int pos = search(inOrder, val,start, end);
    curr->right = buildTree(postOrder, inOrder, pos+1, end);
    curr->left = buildTree(postOrder, inOrder, start, pos-1);

    return curr;
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
    int postOrder[] = {4,2,5,3,1};
    int inOrder[] = {4,2,1,5,3};
    Node* root = buildTree(postOrder, inOrder, 0, 4);
    inOrderPrint(root);
    return 0;
}