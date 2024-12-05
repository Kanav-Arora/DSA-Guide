#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    pair<int, int> caller(Node *root)
    {
        if (!root)
            return {0, 0};

        pair<int, int> lt = caller(root->left);
        pair<int, int> rt = caller(root->right);

        return {root->data + lt.second + rt.second, max(lt.first, lt.second) + max(rt.first, rt.second)};
    }

    int getMaxSum(Node *root)
    {
        pair<int, int> res = caller(root);
        return max(res.first, res.second);
    }
};