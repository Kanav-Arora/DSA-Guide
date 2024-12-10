#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int findCeil(Node *root, int input)
{
    if (!root)
        return -1;
    int ceil = -1;
    Node *temp = root;
    while (temp)
    {
        if (input == temp->data)
            return input;
        if (input < temp->data)
        {
            ceil = temp->data;
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    return ceil;
}