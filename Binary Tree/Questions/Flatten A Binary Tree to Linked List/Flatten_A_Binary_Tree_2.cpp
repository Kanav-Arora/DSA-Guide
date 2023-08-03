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

void flatten(TreeNode *root)
{
    if (root == NULL)
        return;

    if (root->left)
        flatten(root->left);
    if (root->right)
        flatten(root->right);

    if (root->left)
    {
        TreeNode *temp = root->left;
        while (temp->right != NULL)
            temp = temp->right;
        temp->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
}

int main()
{

    return 0;
}