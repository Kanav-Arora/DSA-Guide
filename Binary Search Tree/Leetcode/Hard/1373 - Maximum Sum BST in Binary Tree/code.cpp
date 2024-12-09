#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    using ppt = pair<pair<int, int>, int>;
    ppt caller(TreeNode *root, int &maxi)
    {
        if (!root)
            return {{INT_MAX, INT_MIN}, 0};

        ppt lt = caller(root->left, maxi);
        ppt rt = caller(root->right, maxi);

        if (root->val > lt.first.second && root->val < rt.first.first)
        {
            int sumTill = lt.second + rt.second + root->val;
            maxi = max(maxi, sumTill);
            return {{min(root->val, lt.first.first), max(root->val, rt.first.second)}, sumTill};
        }

        return {{INT_MIN, INT_MAX}, 0};
    }

    int maxSumBST(TreeNode *root)
    {
        int maxiSum = 0;
        ppt res = caller(root, maxiSum);
        return maxiSum;
    }
};