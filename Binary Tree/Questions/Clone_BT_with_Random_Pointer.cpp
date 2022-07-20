#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *random;

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


// GFG: https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1

Node *clonedTree(Node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    Node *node = new Node(tree->data);
    node->left = clonedTree(tree->left);
    node->right = clonedTree(tree->right);

    return node;
}

void mapCloned(Node *tree, Node *clonedNode, map<Node *, Node *> &mapping)
{
    if (tree == NULL || clonedNode == NULL)
        return;

    mapping[tree] = clonedNode;

    mapCloned(tree->left, clonedNode->left, mapping);
    mapCloned(tree->right, clonedNode->right, mapping);
}

void pointRandom(Node *tree, Node *clonedNode, map<Node *, Node *> &mapping)
{
    if (tree == NULL || clonedNode == NULL)
        return;

    clonedNode->random = mapping[tree->random];

    pointRandom(tree->left, clonedNode->left, mapping);
    pointRandom(tree->right, clonedNode->right, mapping);
}

Node *cloneTree(Node *tree)
{
    Node *clonedNode = clonedTree(tree);

    map<Node *, Node *> mapping;

    mapCloned(tree, clonedNode, mapping);

    pointRandom(tree, clonedNode, mapping);

    return clonedNode;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}