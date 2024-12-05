#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{

public:
    int floor(Node *root, int x)
    {
        if (!root)
            return -1;

        if (root->data == x)
            return root->data;

        if (root->data > x)
        {
            return floor(root->left, x);
        }

        int flr = floor(root->right, x);
        return (flr != -1 && flr <= x) ? flr : root->data;
    }
};