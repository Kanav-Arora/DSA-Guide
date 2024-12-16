#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *flattenTree(TreeNode *root)
    {
        if (!root)
            return nullptr;

        TreeNode *leftTail = flattenTree(root->left);
        TreeNode *rightTail = flattenTree(root->right);

        if (leftTail)
        {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        return rightTail ? rightTail : (leftTail ? leftTail : root);
    }

    void flatten(TreeNode *root)
    {
        flattenTree(root);
    }
};