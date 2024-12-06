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
    TreeNode *caller(TreeNode *root, int &k)
    {
        if (!root)
            return NULL;
        TreeNode *lt = caller(root->left, k);
        k--;
        if (k == 0)
            return root;
        TreeNode *rt = caller(root->right, k);

        return lt ? lt : rt;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        return caller(root, k)->val;
    }
};