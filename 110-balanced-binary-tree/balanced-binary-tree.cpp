/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* node) {
        int c = 0;
        if (node == NULL)
            return c;
        c = 1 + max(depth(node->left), depth(node->right));
        return c;
    }
    bool isBalanced(TreeNode* root) {
        TreeNode* node = root;
        if (node == NULL)
            return true;
        int diff = abs(depth(node->left) - depth(node->right)); // 1-2
        if (diff > 1)
            return false;
        return (isBalanced(node->left) && isBalanced(node->right));
    }
};