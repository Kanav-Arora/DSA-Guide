#include <iostream>
#include <vector>
#include <numeric>
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
    void sumPath(TreeNode *root, int targetSum, vector<int> path, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            path.push_back(root->val);
            int sum = reduce(path.begin(), path.end());
            if (sum == targetSum)
            {
                ans.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        sumPath(root->left, targetSum, path, ans);
        sumPath(root->right, targetSum, path, ans);
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        sumPath(root, targetSum, path, ans);
        return ans;
    }
};