#include <iostream>
#include <vector>
#include <climits>
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
    TreeNode *caller(vector<int> nums, int start, int end)
    {
        if (end < start)
            return NULL;
        if (end == start)
            return new TreeNode(nums[start]);
        int maxiIndex = 0;
        pair<int, int> maxi = {INT_MIN, 0};
        for (int i = start; i <= end; i++)
        {
            if (nums[i] > maxi.first)
                maxi = {nums[i], i};
        }

        TreeNode *lt = caller(nums, start, maxi.second - 1);
        TreeNode *rt = caller(nums, maxi.second + 1, end);

        TreeNode *root = new TreeNode(maxi.first, lt, rt);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int n = nums.size();
        return caller(nums, 0, n - 1);
    }
};