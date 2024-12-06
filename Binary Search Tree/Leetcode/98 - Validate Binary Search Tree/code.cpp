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
    bool caller(TreeNode *root, pair<long, long> mp)
    {
        if (!root)
            return true;
        if (root->val <= mp.first || root->val >= mp.second)
            return false;
        bool lt = caller(root->left, {mp.first, root->val});
        bool rt = caller(root->right, {root->val, mp.second});
        return lt && rt;
    }

    bool isValidBST(TreeNode *root)
    {
        return caller(root, {LONG_MIN, LONG_MAX});
    }
};