#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
            if (leftToRight)
            {
                reverse(temp.begin(), temp.end());
            }
            leftToRight = !leftToRight;
            ans.push_back(temp);
        }
        return ans;
    }
};