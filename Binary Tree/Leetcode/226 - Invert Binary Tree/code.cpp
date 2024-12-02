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
    void invertCaller(TreeNode *root)
    {
        if (!root)
            return;
        invertCaller(root->left);
        invertCaller(root->right);

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    TreeNode *invertTree(TreeNode *root)
    {
        invertCaller(root);
        return root;
    }
};