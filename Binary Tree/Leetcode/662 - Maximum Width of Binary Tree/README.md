# Intuition
The width of a binary tree at any level is defined as the number of nodes between the leftmost and rightmost nodes at that level, including null nodes. To efficiently calculate the width, we can use level-order traversal (BFS) and maintain the indices of nodes to determine their relative positions at each level.

# Approach
1. Use a queue to perform level-order traversal. Each queue element contains a pair: the current node and its corresponding horizontal index.
2. At each level:
   - Normalize the indices by subtracting the index of the first node in the level (to prevent overflow).
   - Calculate the width as `last index - first index + 1`.
   - Update the maximum width.
3. For each node, calculate the indices of its left and right children as `2 * current_index + 1` and `2 * current_index + 2` respectively, and push them into the queue.
4. Return the maximum width after traversing all levels.

# Complexity
- Time complexity:  
  $$O(n)$$, where \(n\) is the number of nodes in the tree, as each node is processed exactly once.

- Space complexity:  
  $$O(w)$$, where \(w\) is the maximum width of the tree, due to the queue used for BFS.

# Code
```cpp
/*
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode *, long long>> q; // node, horizontal distance
        q.push({root, 0});
        int ans = 1;
        while (!q.empty())
        {
            int size = q.size();
            long long startInd = q.front().second;
            long long endInd = q.back().second;
            ans = max(ans, int(endInd - startInd + 1));
            for (int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                TreeNode *node = front.first;
                long long dist = front.second - startInd;
                if (node->left)
                    q.push({node->left, 2LL * dist + 1});
                if (node->right)
                    q.push({node->right, 2LL * dist + 2});
            }
        }
        return ans;
    }
};
