// #BT #HEAP

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isCBT(struct Node *tree, int index, int count)
{
    if (tree == NULL)
        return true;

    if (index >= count)
        return false;

    return isCBT(tree->left, 2 * index + 1, count) && isCBT(tree->right, 2 * index + 2, count);
}

bool isOrder(struct Node *tree)
{
    // leaf node
    if (!tree->left && !tree->right)
        return true;

    // only left child
    if (tree->left && !tree->right)
    {
        return tree->data > tree->left->data;
    }

    if (tree->left && tree->right)
    {
        return tree->data > tree->left->data && tree->data > tree->right->data && isOrder(tree->left) && isOrder(tree->right);
    }
}

int totalNodes(struct Node *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + totalNodes(tree->left) + totalNodes(tree->right);
}

bool isHeap(struct Node *tree)
{
    int index = 0;
    int count = totalNodes(tree);
    if (isCBT(tree, index, count) && isOrder(tree))
        return true;
    return false;
}


int main()
{
    
    return 0;
}