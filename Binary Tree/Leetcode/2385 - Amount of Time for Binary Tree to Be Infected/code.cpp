#include <iostream>
#include <unordered_map>
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
    TreeNode *parentMapping(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp, int start)
    {
        if (!root)
            return NULL;

        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;

        TreeNode *lt = parentMapping(root->left, mp, start);
        TreeNode *rt = parentMapping(root->right, mp, start);

        if (lt)
            return lt;
        if (rt)
            return rt;
        if (root->val == start)
            return root;
        return NULL;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> mp;
        unordered_map<TreeNode *, bool> visited;
        TreeNode *startNode = parentMapping(root, mp, start);

        queue<TreeNode *> q;
        q.push(startNode);
        visited[startNode] = 1;
        int t = 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *front = q.front();
                q.pop();
                TreeNode *parent = NULL;
                if (mp.count(front))
                    parent = mp[front];
                if (parent && !visited[parent])
                {
                    q.push(parent);
                    visited[parent] = true;
                }
                if (front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = true;
                }
            }
            cout << endl;
            t++;
        }
        return t - 1;
    }
};