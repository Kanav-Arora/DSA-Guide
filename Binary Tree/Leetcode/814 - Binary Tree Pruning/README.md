# Intuition
To solve the problem, we need to remove all subtrees that do not contain the value `1`. This involves a post-order traversal of the binary tree (processing children before their parent) so that we can determine if a subtree is valid before deciding on the parent node.

# Approach
1. Use a helper function to traverse the tree recursively.
2. For each node:
   - Recursively prune its left and right subtrees.
   - If a subtree's sum is `0` (i.e., it contains no `1`), set the corresponding child pointer to `NULL`.
3. Return the sum of the current node value and its left and right subtree values. This helps determine whether to keep the subtree rooted at this node.
4. If the entire tree's sum is `0`, return `NULL`; otherwise, return the root.

This approach ensures that we traverse the entire tree, removing subtrees as needed.

# Complexity
- **Time complexity:**  
  $$O(n)$$, where \( n \) is the number of nodes in the tree. Each node is visited exactly once.

- **Space complexity:**  
  $$O(h)$$, where \( h \) is the height of the tree. This accounts for the recursion stack.

# Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pruneTreeCaller(TreeNode* root) {
        if (!root) return 0;

        int left = pruneTreeCaller(root->left);
        int right = pruneTreeCaller(root->right);

        if (left == 0) root->left = NULL;
        if (right == 0) root->right = NULL;

        return root->val + left + right;
    }

    TreeNode* pruneTree(TreeNode* root) {
        int val = pruneTreeCaller(root);
        if (val == 0) return NULL;
        return root;
    }
};
