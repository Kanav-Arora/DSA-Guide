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
    void postOrder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};