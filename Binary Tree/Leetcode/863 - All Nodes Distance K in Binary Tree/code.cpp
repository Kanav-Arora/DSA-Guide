#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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
    void parentMapper(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (!root)
            return;
        if (root->left)
        {
            parent[root->left] = root;
            parentMapper(root->left, parent);
        }
        if (root->right)
        {
            parent[root->right] = root;
            parentMapper(root->right, parent);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        unordered_set<TreeNode *> visited;
        parentMapper(root, parent);
        queue<TreeNode *> q;
        q.push(target);
        visited.insert(target);
        while (!q.empty() && k != 0)
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *front = q.front();
                q.pop();
                if (parent.count(front) && !visited.count(parent[front]))
                {
                    q.push(parent[front]);
                    visited.insert(parent[front]);
                }
                if (front->left && !visited.count(front->left))
                {
                    q.push(front->left);
                    visited.insert(front->left);
                }
                if (front->right && !visited.count(front->right))
                {
                    q.push(front->right);
                    visited.insert(front->right);
                }
            }
            k--;
        }

        vector<int> ans;
        if (k != 0 || q.empty())
            return ans;
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};