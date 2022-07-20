#include <iostream>
#include <queue>
#include<vector>
#include<climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }

    if (data > root->data)
        root->right = insert(root->right, data);

    else
        root->left = insert(root->left, data);

    return root;
}

// Leetcode 1008

// Method I: T.C:O(N^2) S.C: O(N)
Node *insertToBST(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }

    if (val > root->data)
        root->right = insertToBST(root->right, val);
    else
        root->left = insertToBST(root->left, val);

    return root;
}

Node *bstFromPreorder(vector<int> &preorder)
{
    Node *root = new Node(preorder[0]);

    if (preorder.size() == 1)
        return root;

    int i = 1;

    while (i < preorder.size() && preorder[i] < preorder[0])
    {
        root->left = insertToBST(root->left, preorder[i]);
        i++;
    }

    while (i < preorder.size())
    {
        root->right = insertToBST(root->right, preorder[i]);
        i++;
    }

    return root;
}

// Method II:

Node *bstFromPreorder(vector<int> &A)
{
    int i = 0;
    return build(A, i, INT_MAX);
}

Node *build(vector<int> &A, int &i, int bound)
{
    if (i == A.size() || A[i] > bound)
        return NULL;
    Node *root = new Node(A[i++]);
    root->left = build(A, i, root->data);
    root->right = build(A, i, bound);
    return root;
}

int main()
{
    Node *root = NULL;
    // 10 7 15 5 9 17 16 19 -1
    return 0;
}