#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode *caller(int preStart, int preEnd, vector<int> &preorder, int inStart, int inEnd, vector<int> &inorder, unordered_map<int, int> &mp)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }

        int rootval = preorder[preStart];
        int rootind = mp[preorder[preStart]];
        TreeNode *root = new TreeNode(rootval);
        int leftLen = rootind - inStart;
        root->left = caller(preStart + 1, preStart + leftLen, preorder, inStart, rootind - 1, inorder, mp);
        root->right = caller(preStart + leftLen + 1, preEnd, preorder, rootind + 1, inEnd, inorder, mp);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }

        return caller(0, n - 1, preorder, 0, n - 1, inorder, mp);
    }
};