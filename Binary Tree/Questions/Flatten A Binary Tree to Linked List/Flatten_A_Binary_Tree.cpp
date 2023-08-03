#include <iostream>
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

void printBT(const std::string &prefix, const Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        std::cout << node->data << std::endl;
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

void printBT(const Node *node)
{
    printBT("", node, false);
}

void leftAndRight(Node *&root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    leftAndRight(root->left);
    leftAndRight(root->right);

    Node *temp = root->right;
    root->right = root->left;
    root->left = NULL;
    root->right->right = temp;
}

void Flatten(Node *root)
{
    // step 1 -> recursively flatten left and right subtree

    leftAndRight(root->left);
    leftAndRight(root->right);

    // step 2 -> store left tail and right tail

    Node *lefttail = root->left;
    Node *righttail = root->right;

    while (lefttail->right != NULL)
        lefttail = lefttail->right;

    while (righttail->right != NULL)
        righttail = righttail->right;

    Node *temp = root->right;

    root->right = root->left;
    root->left = NULL;

    lefttail->right = temp;

    printBT(root);
}

// Above solution merged into one

void flatten(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    flatten(root->left);
    flatten(root->right);
    if (root->left)
    {
        Node *right = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right)
            root = root->right;
        root->right = right;
    }
}

// Using Morris Law

void FlattenUsingMorris(Node *root)
{
    Node *curr = root;

    while (curr)
    {
        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right)
                pred = pred->right;

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

// Using Reverse Preorder

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printBT(root);
    FlattenUsingMorris(root);
    printBT(root);

    return 0;
}