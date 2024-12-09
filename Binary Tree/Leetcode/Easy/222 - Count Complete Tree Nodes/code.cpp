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
    void inOrder(TreeNode *root, int &cnt)
    {
        if (root == NULL)
        {
            return;
        }

        inOrder(root->left, cnt);
        cnt++;
        inOrder(root->right, cnt);
    }
    int countNodes(TreeNode *root)
    {
        int cnt = 0;
        inOrder(root, cnt);

        return cnt;
    }
};