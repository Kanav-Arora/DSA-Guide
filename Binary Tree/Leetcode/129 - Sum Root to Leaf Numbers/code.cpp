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
    void caller(TreeNode *root, string val, vector<int> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            string data = val + to_string(root->val);
            ans.push_back(stoi(data));
            return;
        }

        string data = val + to_string(root->val);
        if (root->left)
            caller(root->left, data, ans);
        if (root->right)
            caller(root->right, data, ans);
    }

    int sumNumbers(TreeNode *root)
    {
        vector<int> ans;
        caller(root, "", ans);
        return reduce(ans.begin(), ans.end());
    }
};