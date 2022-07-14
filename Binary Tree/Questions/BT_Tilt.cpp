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


// Question Leetcode : 563.

int Tilt(Node *&root)
{
    if (root->left == NULL && root->right == NULL)
    {
        int data = root->data;
        root->data = 0;
        return data;
    }

    int lt = Tilt(root->left);
    int rt = Tilt(root->right);

    int sum = root->data + lt + rt;

    root->data = abs(lt - rt);

    return sum;
}

int helper(Node *root)
{
    if (root == NULL)
        return 0;

    return root->data + helper(root->left) + helper(root->right);
}

int findTilt(Node *root)
{
    int val = Tilt(root);
    return helper(root);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}