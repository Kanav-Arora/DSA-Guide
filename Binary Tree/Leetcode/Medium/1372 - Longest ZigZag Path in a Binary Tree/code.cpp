#include <iostream>
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
    int caller(TreeNode *root, string call, int &maxi)
    {
        if (!root)
            return 0;

        int lt = caller(root->left, "lt", maxi);
        int rt = caller(root->right, "rt", maxi);

        maxi = max(maxi, max(lt, rt));

        return 1 + (call == "lt" ? rt : lt);
    }
    int longestZigZag(TreeNode *root)
    {
        int maxi = 0;
        int lt = caller(root->left, "lt", maxi);
        int rt = caller(root->right, "rt", maxi);
        maxi = max(maxi, max(lt, rt));
        return maxi;
    }
};