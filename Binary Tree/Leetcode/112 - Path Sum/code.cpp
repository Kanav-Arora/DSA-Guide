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
    bool sumPath(TreeNode *root, int targetSum, int sum)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
        {
            return (sum + root->val) == targetSum;
        }

        bool left = sumPath(root->left, targetSum, sum + root->val);
        bool right = sumPath(root->right, targetSum, sum + root->val);

        return left || right;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return sumPath(root, targetSum, 0);
    }
};