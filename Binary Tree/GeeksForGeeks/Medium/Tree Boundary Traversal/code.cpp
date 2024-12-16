#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    void leftPath(Node *root, vector<int> &path)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        path.push_back(root->data);

        if (root->left)
            leftPath(root->left, path);
        else
            leftPath(root->right, path);
    }

    void leafPath(Node *root, vector<int> &path)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            path.push_back(root->data);
            return;
        }

        leafPath(root->left, path);
        leafPath(root->right, path);
    }

    void rightPath(Node *root, vector<int> &path)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->right)
            rightPath(root->right, path);
        else
            rightPath(root->left, path);

        path.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> path;
        if (root == NULL)
            return path;

        path.push_back(root->data);

        leftPath(root->left, path);
        leafPath(root->left, path);
        leafPath(root->right, path);
        rightPath(root->right, path);

        return path;
    }
};