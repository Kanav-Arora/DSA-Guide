#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *caller(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode *lt = caller(root->left, p, q);
        TreeNode *rt = caller(root->right, p, q);

        if (lt && rt)
            return root;
        return lt ? lt : rt;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return caller(root, p, q);
    }
};