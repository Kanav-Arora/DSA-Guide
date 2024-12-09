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
    pair<int, int> caller(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        if (!root->left && !root->right)
            return {root->val, 0};
        auto lt = caller(root->left);
        auto rt = caller(root->right);

        int actualSum = root->val + lt.first + rt.first;
        int tiltSum = lt.second + rt.second + abs(lt.first - rt.first);

        return {actualSum, tiltSum};
    }

    int findTilt(TreeNode *root)
    {
        return caller(root).second;
    }
};