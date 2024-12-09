#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
    static bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }

    void caller(TreeNode *root, map<int, vector<pair<int, int>>> &mp, int pos, int height)
    {
        if (!root)
            return;

        if (!mp.count(pos))
            mp[pos] = vector<pair<int, int>>(0);
        mp[pos].push_back({root->val, height});
        caller(root->left, mp, pos - 1, height + 1);
        caller(root->right, mp, pos + 1, height + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        map<int, vector<pair<int, int>>> mp;
        caller(root, mp, 0, 0);

        vector<vector<pair<int, int>>> temp;
        for (auto each : mp)
        {
            temp.push_back(each.second);
        }

        for (auto each : temp)
        {
            vector<int> vec;
            sort(each.begin(), each.end(), comp);
            for (auto a : each)
            {
                vec.push_back(a.first);
            }
            ans.push_back(vec);
        }

        return ans;
    }
};