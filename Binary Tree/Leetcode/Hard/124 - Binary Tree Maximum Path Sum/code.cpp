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
    int caller(TreeNode *root, int &maxi)
    {
        if (!root)
            return 0;

        int lt = caller(root->left, maxi);
        int rt = caller(root->right, maxi);
        if (lt < 0)
            lt = 0;
        if (rt < 0)
            rt = 0;

        maxi = max(maxi, root->val + lt + rt);

        return root->val + max(lt, rt);
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        caller(root, maxi);
        return maxi;
    }
};