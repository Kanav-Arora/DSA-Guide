#include <iostream>
#include <vector>
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
    int pruneTreeCaller(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = pruneTreeCaller(root->left);
        int right = pruneTreeCaller(root->right);

        if (left == 0)
            root->left = NULL;
        if (right == 0)
            root->right = NULL;

        return root->val + left + right;
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        int val = pruneTreeCaller(root);
        if (val == 0)
            return NULL;
        return root;
    }
};