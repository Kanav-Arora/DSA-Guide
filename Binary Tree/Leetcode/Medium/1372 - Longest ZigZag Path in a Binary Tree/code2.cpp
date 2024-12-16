#include <iostream>
#include <vector>
#include <map>
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
    void solver(TreeNode *root, map<TreeNode *, pair<int, int>> &mp)
    {
        if (root == NULL)
            return;

        solver(root->left, mp);
        solver(root->right, mp);
        if (root->left && root->right)
        {
            mp[root] = {1 + mp[root->left].second, 1 + mp[root->right].first};
        }
        else if (root->left)
        {
            mp[root] = {1 + mp[root->left].second, 0};
        }
        else if (root->right)
        {
            mp[root] = {0, 1 + mp[root->right].first};
        }
        else
        {
            mp[root] = {0, 0};
        }
    }

public:
    int longestZigZag(TreeNode *root)
    {
        map<TreeNode *, pair<int, int>> mp;
        solver(root, mp);
        int ans = 0;
        for (auto i : mp)
        {
            ans = max(ans, i.second.first);
            ans = max(ans, i.second.second);
        }
        return ans;
    }
};