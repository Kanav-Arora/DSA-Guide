#include <iostream>
#include <vector>
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
    int caller(TreeNode *root, int &maxi)
    {
        if (!root)
            return 0;
        int lt = caller(root->left, maxi);
        int rt = caller(root->right, maxi);
        maxi = max(maxi, lt + rt);
        return 1 + max(lt, rt);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        int val = caller(root, maxi);
        return maxi;
    }
};