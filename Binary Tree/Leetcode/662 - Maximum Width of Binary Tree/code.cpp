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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode *, int>> q; // node, horizontal distance
        q.push({root, 0});
        int ans = 1;
        while (!q.empty())
        {
            int size = q.size();
            int startInd = q.front().second;
            int endInd = q.back().second;
            ans = max(endInd - startInd + 1, ans);
            for (int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                TreeNode *node = front.first;
                int dist = front.second - startInd;
                if (node->left)
                    q.push({node->left, 2LL * dist + 1});
                if (node->right)
                    q.push({node->right, 2LL * dist + 2});
            }
        }
        return ans;
    }
};