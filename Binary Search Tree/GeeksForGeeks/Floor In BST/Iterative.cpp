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
        int floor = -1;
        Node *temp = root;
        while (temp)
        {
            if (temp->data == x)
                return x;
            if (x < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                floor = temp->data;
                temp = temp->right;
            }
        }
        return floor;
    }
};